/*--------------------------------------------------------------------------

	Copyright © 2021, Yoshiki Tanaka
	
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*///------------------------------------------------------------------------

#include <main_window.hpp>
#include <ui_main_window.h>

#include <QMainWindow>
#include <QDialogButtonBox>
#include <QString>
#include <QVector>
#include <QStringList>
#include <QObject>
#include <QDirIterator>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QApplication>
#include <QSettings>
#include <QTextCodec>

// ある文字列で囲まれた文字列抽出
QStringList MainWindow::search_inside(const QString& str, const QString& start, const QString& end)const
{
    auto start_indexs = QVector<int>();
    auto end_indexs = QVector<int>();

    int pos = str.indexOf(start);
    for(; pos != -1; pos = str.indexOf(start, ++pos))
        start_indexs.push_back(pos + start.length());

    pos = str.indexOf(end);
    for(; pos != -1; pos = str.indexOf(end, ++pos))
        end_indexs.push_back(pos);

    if(start_indexs.size() != end_indexs.size())
        throw QString(this->tr("置換目印の先頭と終端の数が合いません"));

    auto result = QStringList();
    for(int ind=0; ind<start_indexs.size(); ++ind)
        result += str.mid(start_indexs[ind], end_indexs[ind] - start_indexs[ind]);

    return result;
}

// あるフォルダ下全てのフォルダ名とファイル名の置換サイン検索
QStringList MainWindow::search_sign_name(const QString& dir)const
{
    auto dirs_itr = QDirIterator
    (
        dir,
        QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files,
        QDirIterator::Subdirectories
    );

    auto dirs = QStringList();
    auto signs = QStringList();

    while(dirs_itr.hasNext())
        dirs += dirs_itr.next();

    try
    {
        for(const auto& i:dirs)
            signs += this->search_inside(i,
                this->setting_.value("replace_sign_head", this->default_replace_sign_head_).toString(),
                this->setting_.value("replace_sign_end", this->default_replace_sign_end_).toString());
    } catch(const QString err)
    {
        throw err;
    }

    signs.removeDuplicates();//重複削除

    return signs;
}

// あるフォルダ下全てのファイル内の置換サイン検索
QStringList MainWindow::search_sign_file(const QString& path)const
{
    auto files_itr = QDirIterator
    (
        path,
        QDir::NoDotAndDotDot | QDir::Files,
        QDirIterator::Subdirectories
    );

    auto file_names = QStringList();
    auto signs = QStringList();

    while(files_itr.hasNext())
        file_names += files_itr.next();

    for(const auto& i:file_names)
    {
        auto file = QFile(i);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            throw QString(this->tr("存在しないファイルが含まれています"));

        QTextStream stream(&file);

        auto buffer = QString();

        try
        {
            while (!stream.atEnd())
            {
                buffer = stream.readLine();
                signs += search_inside(buffer,
                    this->setting_.value("replace_sign_head", this->default_replace_sign_head_).toString(),
                    this->setting_.value("replace_sign_end", this->default_replace_sign_end_).toString());
            }
        }catch(const QString err)
        {
            throw err;
        }

        signs.removeDuplicates();//重複削除
        file.close();
    }

    return signs;
}

// フォルダ内をすべて置換&コピー
void MainWindow::copy_replace_folder(const QString& in, const QString& out, const QStringList& signs, const QStringList& names)const
{
    QDir in_dir(in);
    if(!in_dir.exists())
        throw QString(this->tr("存在しないディレクトリが含まれています"));

    auto under_dirs = in_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    auto under_dirs_replace = under_dirs;

    for(int i=0; i<signs.size(); ++i)
        under_dirs_replace.replaceInStrings(
            this->setting_.value("replace_sign_head", this->default_replace_sign_head_).toString() +
            signs[i] +
            this->setting_.value("replace_sign_end", this->default_replace_sign_end_).toString(),
            names[i]);

    for(int i=0; i<under_dirs.size(); ++i)
    {
        auto out_path = QString(out + QDir::separator() + under_dirs_replace[i]);
        in_dir.mkpath(out_path);
        this->ui_->progress->add_line(this->tr("create dir:") + out_path);
        this->ui_->progress->inc_nominator();
        this->copy_replace_folder(in + QDir::separator() + under_dirs[i], out_path, signs, names);
    }

    auto under_files = in_dir.entryList(QDir::Files);
    auto under_files_replaced = under_files;
    for(int i=0; i<signs.size(); ++i)
        under_files_replaced.replaceInStrings(
            this->setting_.value("replace_sign_head", this->default_replace_sign_head_).toString() +
            signs[i] +
            this->setting_.value("replace_sign_end", this->default_replace_sign_end_).toString(),
            names[i]);

    for(int i=0; i<under_files.size(); ++i)
    {
        QFile::copy(in + QDir::separator() + under_files[i], out + QDir::separator() + under_files_replaced[i]);
        this->ui_->progress->add_line(this->tr("create file:") + out + QDir::separator() + under_files_replaced[i]);
        this->ui_->progress->inc_nominator();

        QFileInfo fi;
        fi.setFile(out + QDir::separator() + under_files_replaced[i]);
        auto extension = fi.suffix();

        bool hit = false;
        for(const auto& exe:this->textfile_extensions_)
            if(exe == extension) hit = true;

        if(hit)
            this->replace_file_text(out + QDir::separator() + under_files_replaced[i], signs, names);
    }
}

// ファイル内のテキストを置換
void MainWindow::replace_file_text(const QString& path, const QStringList& signs, const QStringList& names)const
{
    auto file = QFile(path);

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        file.close();
        return;
    }

    auto stream = QTextStream(&file);
    auto buffer = QString();
    auto out_str = QString();

    while(!stream.atEnd())
    {
        buffer = stream.readLine();

        for(int i=0; i<signs.size(); ++i)
            buffer.replace(
                this->setting_.value("replace_sign_head", this->default_replace_sign_head_).toString() +
                signs[i] +
                this->setting_.value("replace_sign_end", this->default_replace_sign_end_).toString(),
                names[i]);

        if(!buffer.contains("DELETE"))
            out_str.append(buffer + "\n");
    }

    file.resize(0);
    stream << out_str;
    file.close();
}

// テキストファイルと認識される拡張子リストの読み込み
void MainWindow::load_text_extensions_file(const QString& filename)
{
    auto file = QFile(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file.close();
        return;
    }

    auto stream = QTextStream(&file);
    auto buffer = QString();

    while(!stream.atEnd())
    {
        buffer = stream.readLine();
        this->textfile_extensions_ += buffer;
    }

    file.close();
}

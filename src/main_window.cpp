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
#include <stdexcept>
#include <QDirIterator>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
:	QMainWindow(parent), 
    ui_(new Ui::MainWindowUiRoot),
    wizard_path_("../wizard"),
    rep_sign_start_("__$"),
    rep_sign_end_("$__")
{
    this->ui_->setupUi(this);

    this->connect(this->ui_->buttonBox, &QDialogButtonBox::accepted, this, &MainWindow::clicked_accept);
    this->connect(this->ui_->buttonBox, &QDialogButtonBox::rejected, this, &MainWindow::close);
    this->connect(this->ui_->project_name_list, &ProNameList::clicked_project_name, this, &MainWindow::clicked_prj_list);

    this->ui_->project_name_list->set_wizard_dir(this->wizard_path_);
}

MainWindow::~MainWindow()
{
    delete this->ui_;
}

// acceptボタンが押されたとき呼ばれるスロット
void MainWindow::clicked_accept()
{
    auto error_list = QStringList();

    if(!this->ui_->replace_view->is_names_full())
    {
        QMessageBox msg(this);
        msg.setText(this->tr("置換文字リストが全て埋まっていません。"));
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }

    auto signs = this->ui_->replace_view->get_sign_list();// 置換リストの置換目印リスト
    auto names = this->ui_->replace_view->get_name_list();// 置換リストの置き換え文字リスト

    QDir(this->ui_->out_put_text_box->text()).mkdir(names[0]);

    auto in_dir_path = this->wizard_path_ + QDir::separator() + this->ui_->project_name_list->selected_prj_name();
    auto out_dir_path = this->ui_->out_put_text_box->text() + QDir::separator() + names[0];

    try
    {
        this->copy_replace_folder(in_dir_path, out_dir_path, signs, names);
    }catch(const std::runtime_error err)
    {
        QMessageBox msg(this);
        msg.setText(this->tr("ファイルの置換とコピーに失敗しました"));
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }
}

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
        throw std::runtime_error("There is a problem with how to write the replacement sign");

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
            signs += this->search_inside(i, this->rep_sign_start_, this->rep_sign_end_);
    } catch(const std::runtime_error err)
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
            throw std::runtime_error("cant open file");

        QTextStream stream(&file);

        auto buffer = QString();

        try
        {
            while (!stream.atEnd())
            {
                buffer = stream.readLine();
                signs += search_inside(buffer, this->rep_sign_start_, this->rep_sign_end_);
            }
        }catch(const std::runtime_error err)
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
        throw std::runtime_error("cant copy and replace filder");

    auto under_dirs = in_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    auto under_dirs_replace = under_dirs;

    for(int i=0; i<signs.size(); ++i)
        under_dirs_replace.replaceInStrings(this->rep_sign_start_ + signs[i] + this->rep_sign_end_, names[i]);

    for(int i=0; i<under_dirs.size(); ++i)
    {
        auto out_path = QString(out + QDir::separator() + under_dirs_replace[i]);
        in_dir.mkpath(out_path);
        this->copy_replace_folder(in + QDir::separator() + under_dirs[i], out_path, signs, names);
    }

    auto under_files = in_dir.entryList(QDir::Files);
    auto under_files_replaced = under_files;
    for(int i=0; i<signs.size(); ++i)
        under_files_replaced.replaceInStrings(this->rep_sign_start_ + signs[i] + this->rep_sign_end_, names[i]);

    for(int i=0; i<under_files.size(); ++i)
    {
        QFile::copy(in + QDir::separator() + under_files[i], out + QDir::separator() + under_files_replaced[i]);
        this->replace_file_text(out + QDir::separator() + under_files_replaced[i], signs, names);
    }
}

// ファイル内のテキストを置換
void MainWindow::replace_file_text(const QString& path, const QStringList& signs, const QStringList& names)const
{
    auto file = QFile(path);

    if(file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        auto stream = QTextStream(&file);
        auto buffer = QString();

        auto out_str = QString();

        while(!stream.atEnd())
        {
            buffer = stream.readLine();
            for(int i=0; i<signs.size(); ++i)
                buffer.replace(this->rep_sign_start_ + signs[i] + this->rep_sign_end_, names[i]);

            if(!buffer.contains("DELETE"))
                out_str.append(buffer + "\n");
        }

        file.resize(0);
        stream << out_str;
    }

    file.close();
}

// プロジェクトリストが押されたとき呼ばれるスロット
void MainWindow::clicked_prj_list(const QString& prj_name)
{
    this->ui_->replace_view->all_clear();

    auto rep_sign_list = QStringList();
    rep_sign_list += this->tr("project_name");

    try
    {
        rep_sign_list += this->search_sign_name(this->wizard_path_ + QDir::separator() + prj_name);
        rep_sign_list += this->search_sign_file(this->wizard_path_ + QDir::separator() + prj_name);
    }catch(const std::runtime_error err)
    {
        QMessageBox msg(this);
        msg.setText(this->tr("置換文字列の目印に問題がある可能性があります"));
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }

    rep_sign_list.removeDuplicates();//重複削除

    this->ui_->replace_view->add_sign_list(rep_sign_list);
}

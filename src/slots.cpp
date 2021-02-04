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
#include <setting_dialog.hpp>

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

// acceptボタンが押されたとき呼ばれるスロット
void MainWindow::clicked_accept()
{
    if(!this->ui_->project_name_list->is_selected())
    {
        QMessageBox msg(this);
        msg.setText(this->tr("生成するプロジェクトが選択されていません"));
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }

    if(!this->ui_->replace_view->is_names_full())
    {
        QMessageBox msg(this);
        msg.setText(this->tr("置き換え文字リストが全て埋まっていません。"));
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }

    QMessageBox will_do_you(this);
    will_do_you.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    will_do_you.setText(this->tr("プロジェクトの作成を行いますか?"));
    will_do_you.setWindowTitle(this->tr("メッセージ"));
    if(will_do_you.exec() == QMessageBox::No)
        return;

    auto signs = this->ui_->replace_view->get_sign_list();// 置換リストの置換目印リスト
    auto names = this->ui_->replace_view->get_name_list();// 置換リストの置き換え文字リスト

    QDir(this->ui_->out_put_text_box->text()).mkdir(names[0]);

    auto in_dir_path = this->setting_.value("wizard_dir", this->default_wizard_path_).toString() + QDir::separator() + this->ui_->project_name_list->selected_prj_name();
    auto out_dir_path = this->ui_->out_put_text_box->text() + QDir::separator() + names[0];

    auto dir_itr = QDirIterator(in_dir_path, QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files, QDirIterator::Subdirectories);
    while(dir_itr.hasNext())
    {
        dir_itr.next();
        this->ui_->progress->inc_denominator();
    }

    try
    {
        this->copy_replace_folder(in_dir_path, out_dir_path, signs, names);
    }catch(const QString err)
    {
        QMessageBox msg(this);
        msg.setText(err);
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }

    QMessageBox msg(this);
    msg.setText(this->tr("プロジェクトの生成が完了しました"));
    msg.setWindowTitle(this->tr("メッセージ"));
    msg.exec();
}

// プロジェクトリストが押されたとき呼ばれるスロット
void MainWindow::clicked_prj_list(const QString& prj_name)
{
    this->ui_->replace_view->all_clear();
    this->ui_->progress->clear_all();

    auto rep_sign_list = QStringList();
    rep_sign_list += this->tr("project_name");

    try
    {
        rep_sign_list += this->search_sign_name(
            this->setting_.value("wizard_dir", this->default_wizard_path_).toString() +
            QDir::separator() +
            prj_name);

        rep_sign_list += this->search_sign_file(
            this->setting_.value("wizard_dir", this->default_wizard_path_).toString() +
            QDir::separator() +
            prj_name);

    }catch(const QString err)
    {
        QMessageBox msg(this);
        msg.setText(err);
        msg.setWindowTitle(this->tr("エラー"));
        msg.exec();
        return;
    }

    rep_sign_list.removeDuplicates();//重複削除

    this->ui_->replace_view->add_sign_list(rep_sign_list);
}

// 設定アクションがクリックされたとき呼び出し
void MainWindow::clicked_setting()
{
    SettingDialog sdl;
    auto result = sdl.exec();
    if(result)
    {
        this->ui_->project_name_list->set_wizard_dir(this->setting_.value("wizard_dir", this->default_wizard_path_).toString());
        this->ui_->replace_view->all_clear();
    }
}

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

// プロジェクトリストが押されたとき呼ばれるスロット
void MainWindow::clicked_prj_list(const QString& prj_name)
{
    this->ui_->replace_view->all_clear();

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

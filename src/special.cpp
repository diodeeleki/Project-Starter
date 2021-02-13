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

MainWindow::MainWindow(QWidget *parent)
:	QMainWindow(parent), 
    ui_(new Ui::MainWindowUiRoot),
    init_file_path_(QApplication::applicationDirPath() + QDir::separator() + ".." + QDir::separator() + "init" + QDir::separator() + "pjs.ini"),
    default_replace_sign_head_("__$"),
    default_replace_sign_end_("$__"),
    default_wizard_path_(QApplication::applicationDirPath() + QDir::separator() + ".." + QDir::separator() + "wizard"),
    setting_(this->init_file_path_, QSettings::IniFormat)
{
    this->setting_.setIniCodec(QTextCodec::codecForName("UTF-8"));

    this->ui_->setupUi(this);

    this->connect(this->ui_->buttonBox, &QDialogButtonBox::accepted, this, &MainWindow::clicked_accept);
    this->connect(this->ui_->buttonBox, &QDialogButtonBox::rejected, this, &MainWindow::close);
    this->connect(this->ui_->project_name_list, &ProNameList::clicked_project_name, this, &MainWindow::clicked_prj_list);
    this->connect(this->ui_->action_setting, &QAction::triggered, this, &MainWindow::clicked_setting);

    this->ui_->project_name_list->set_wizard_dir(this->setting_.value("wizard_dir", this->default_wizard_path_).toString());

    this->load_text_extensions_file("../etc/text_type_extensions.txt");
}

MainWindow::~MainWindow()
{
    delete this->ui_;
}

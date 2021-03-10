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

#include <setting_dialog.hpp>
#include <ui_setting_dialog.h>

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QApplication>
#include <QSettings>
#include <QMessageBox>

SettingDialog::SettingDialog(QWidget* parent)
:   QDialog(parent),
    ui_(new Ui::SettingDialogUi),
    ini_path_(QApplication::applicationDirPath() + QDir::separator() + ".." + QDir::separator() + "init" + QDir::separator() + "pjs.ini"),
    default_wizard_path_(QApplication::applicationDirPath() + QDir::separator() + ".." + QDir::separator() + "wizard"),
    setting_(this->ini_path_, QSettings::IniFormat)
{
    this->ui_->setupUi(this);
    this->ui_->wizard_dir_line_edit->title(this->tr("ウィザードパス"));
    
    this->connect(this->ui_->buttonBox, &QDialogButtonBox::rejected, this, &SettingDialog::clocked_rejected);
    this->connect(this->ui_->buttonBox, &QDialogButtonBox::accepted, this, &SettingDialog::clocked_accept);
    this->connect(this->ui_->default_button, &QPushButton::clicked, this, &SettingDialog::clicked_default);

    this->ui_->replace_sign_head->setText(this->setting_.value("replace_sign_head", "__$").toString());
    this->ui_->replace_sign_end->setText(this->setting_.value("replace_sign_end", "$__").toString());
    this->ui_->wizard_dir_line_edit->text(this->setting_.value("wizard_dir", this->default_wizard_path_).toString());
}

SettingDialog::~SettingDialog()
{
    delete this->ui_;
}

// rejectボタンが押されたら実行
void SettingDialog::clocked_rejected()
{
	this->reject();
}

// acceptボタンが押されたら実行
void SettingDialog::clocked_accept()
{
    if(this->ui_->replace_sign_head->text() != "" &&
       this->ui_->replace_sign_end->text() != "" &&
       this->ui_->wizard_dir_line_edit->text() != "")
    {
        this->setting_.setValue("wizard_dir", this->ui_->wizard_dir_line_edit->text());
        this->setting_.setValue("replace_sign_head", this->ui_->replace_sign_head->text());
        this->setting_.setValue("replace_sign_end", this->ui_->replace_sign_end->text());

        QMessageBox msg;
        msg.setText(this->tr("設定を変更しました"));
        msg.setWindowTitle(tr("メッセージ"));
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();

        this->accept();
    }else
    {
        QMessageBox msg;
        msg.setText(this->tr("項目に空白があります"));
        msg.setWindowTitle(tr("エラー"));
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
    }
}

void SettingDialog::clicked_default()
{
    this->ui_->replace_sign_head->setText("__$");
    this->ui_->replace_sign_end->setText("$__");
    this->ui_->wizard_dir_line_edit->text(this->default_wizard_path_);
}

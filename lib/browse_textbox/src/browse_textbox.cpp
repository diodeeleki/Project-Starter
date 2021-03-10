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

#include <browse_textbox.hpp>
#include <ui_browse_textbox.h>

#include <QWidget>
#include <QFileDialog>
#include <QDir>

BrowseTextbox::BrowseTextbox(QWidget *parent)
:	QWidget(parent), 
	ui_(new Ui::BrowseTextboxUiRoot)
{
    this->ui_->setupUi(this);
    this->connect(this->ui_->pushButton, SIGNAL(clicked()), this, SLOT(clicked_browse_button()));
    this->ui_->lineEdit->setText(QDir::currentPath());
}

BrowseTextbox::~BrowseTextbox()
{
    delete this->ui_;
}

void BrowseTextbox::clicked_browse_button()
{
	QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
	dialog.setDirectory(this->ui_->lineEdit->text());
	dialog.exec();
	
	QDir dir = dialog.directory();
	this->ui_->lineEdit->setText(dir.path());
}

QString BrowseTextbox::text()const
{
    return this->ui_->lineEdit->text();
}

void BrowseTextbox::text(const QString& str)
{
    return this->ui_->lineEdit->setText(str);
}

void BrowseTextbox::title(const QString& new_title)
{
    this->ui_->groupBox->setTitle(new_title);
}

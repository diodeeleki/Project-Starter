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

#include <pro_name_list.hpp>
#include <ui_pro_name_list.h>

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QDirIterator>
#include <QModelIndex>

ProNameList::ProNameList(QWidget *parent)
:	QWidget(parent), 
	ui_(new Ui::ProNameListUiRoot)
{
    this->ui_->setupUi(this);
    this->ui_->listView->setModel(&this->model_);

    this->connect(this->ui_->listView, &QListView::clicked, this, &ProNameList::select_project);
}

ProNameList::~ProNameList()
{
    delete this->ui_;
}

void ProNameList::set_wizard_dir(const QString& dir)
{
    auto wizard_below_dirs = QDirIterator(dir, QDir::NoDotAndDotDot | QDir::Dirs, QDirIterator::NoIteratorFlags);
    auto wizard_below_names = QStringList();

    /*------------------------------------------------------------------------

        ここからwizardディレクトリ直下のディレクトリ名からプロジェクト名抽出

    *///----------------------------------------------------------------------
    while(wizard_below_dirs.hasNext())
        wizard_below_names += wizard_below_dirs.next();

    wizard_below_names.replaceInStrings( dir + "/" , "");

    this->model_.setStringList(wizard_below_names);
}

void ProNameList::select_project(const QModelIndex& index)
{
    auto selected_after_ = index.data().toString();

    if(this->selected_before_ != selected_after_)
        emit clicked_project_name(selected_after_);

    this->selected_before_ = selected_after_;
}

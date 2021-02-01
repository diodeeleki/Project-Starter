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

#include <relpace_view.hpp>
#include <ui_relpace_view.h>

#include <QWidget>
#include <QStringList>
#include <cstddef>

RelpaceView::RelpaceView(QWidget *parent)
:	QWidget(parent), 
	ui_(new Ui::RelpaceViewUiRoot)
{
    this->ui_->setupUi(this);
    this->ui_->replace_sign->setModel(&this->sign_model_);
    this->ui_->replace_name->setModel(&this->name_model_);

}

RelpaceView::~RelpaceView()
{
    delete this->ui_;
}

void RelpaceView::add_sign_list(const QStringList& signs)
{
    this->sign_model_.setStringList(signs);
    auto empty_name_list = QStringList();

    empty_name_list.reserve(signs.size());
    for(int i=0; i<signs.size(); ++i)
        empty_name_list += "";

    this->name_model_.setStringList(empty_name_list);
}

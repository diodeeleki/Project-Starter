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

#pragma once

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{ 
	class BrowseTextboxUiRoot; 
}
QT_END_NAMESPACE

class BrowseTextbox
: public QWidget
{
    Q_OBJECT

	Ui::BrowseTextboxUiRoot *ui_;
public:
    BrowseTextbox(QWidget* = nullptr);
    ~BrowseTextbox();

    QString text()const;

public slots:
    void clicked_browse_button();

};

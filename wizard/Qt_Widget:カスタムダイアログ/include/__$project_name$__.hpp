/*--------------------------------------------------------------------------

	Copyright © __$year$__, __$auther$__
	
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

#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{ 
	class __$ui_name$__; 
}
QT_END_NAMESPACE

class __$class_name$__
: public QDialog
{
    Q_OBJECT

	Ui::__$ui_name$__ *ui_;
public:
    __$class_name$__(QWidget* = nullptr);
    ~__$class_name$__();
    
private slots:
	void clocked_rejected();
	void clocked_accept();
};

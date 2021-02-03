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

#include <QDialog>
#include <QString>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui
{ 
	class SettingDialogUi; 
}
QT_END_NAMESPACE

class SettingDialog
: public QDialog
{
    Q_OBJECT

	Ui::SettingDialogUi *ui_;

    const QString ini_path_;
    const QString default_wizard_path_;
    QSettings setting_;

public:
    SettingDialog(QWidget* = nullptr);
    ~SettingDialog();
    
private slots:
	void clocked_rejected();
	void clocked_accept();
    void clicked_default();

};

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

#include <QApplication>
#include <QObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProNameList w;
    w.set_wizard_dir("../../wizard");
    QObject::connect(&w, &ProNameList::clicked_project_name, [](const QString& prj_name){qDebug() << prj_name;});
    w.show();
    return a.exec();
}

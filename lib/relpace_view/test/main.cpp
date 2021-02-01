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

#include <QApplication>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RelpaceView w;

    auto list = QStringList();
    list += "python";
    list += "c";
    list += "c++";
    list += "ada";
    list += "c#";

    w.add_sign_list(list);

    auto names = w.get_name_list();
    auto signs = w.get_sign_list();

    for(const auto& i:names)
        qDebug() << i;

    for(const auto& i:signs)
        qDebug() << i;

    w.show();
    return a.exec();
}

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
	class progress_bar_ui; 
}
QT_END_NAMESPACE

class ProgressBar
: public QWidget
{
    Q_OBJECT

	Ui::progress_bar_ui* ui_;

    unsigned long long denominator_;// 分母
    unsigned long long nominator_;// 分子
public:
    ProgressBar(QWidget* = nullptr);
    ~ProgressBar();

    void add_line(const QString&);
    void clear_text();

    void inc_denominator();
    void inc_nominator();

    void clear_counter();

    void clear_all();

private:
    void calc_pasent();//分母と分子から％を計算して表示変更
};

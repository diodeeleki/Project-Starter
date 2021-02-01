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
#include <QStringListModel>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui
{ 
	class RelpaceViewUiRoot; 
}
QT_END_NAMESPACE

class RelpaceView
: public QWidget
{
    Q_OBJECT

    Ui::RelpaceViewUiRoot* ui_;

    QStringListModel sign_model_;
    QStringListModel name_model_;
public:
    RelpaceView(QWidget* = nullptr);
    ~RelpaceView();

    // 置換要素リスト読み込み
    void add_sign_list(const QStringList&);

    // 置換名リストがすべて埋まっているか
    bool is_names_full()const
    {
        bool result = true;

        for(auto&& name:this->get_name_list())
            if(name == "") result = false;

        return result;
    }

    // 置換要素リストのゲッター
    QStringList get_sign_list()const
    {
        return this->sign_model_.stringList();
    }

    // 置換名リストのゲッター
    QStringList get_name_list()const
    {
        return this->name_model_.stringList();
    }

    // 全消去
    void all_clear()
    {
        this->sign_model_.removeRows( 0, this->sign_model_.rowCount());
        this->name_model_.removeRows( 0, this->name_model_.rowCount());
    }
};

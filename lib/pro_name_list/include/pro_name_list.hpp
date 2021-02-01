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
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui
{ 
	class ProNameListUiRoot; 
}
QT_END_NAMESPACE

class ProNameList
: public QWidget
{
    Q_OBJECT

    Ui::ProNameListUiRoot* ui_;

    QStringListModel model_;

    QString selected_before_;

public:
    ProNameList(QWidget* = nullptr);
    ~ProNameList();

    // ウィザードディレクトリを読み込み表示
    void set_wizard_dir(const QString&);

    const QString& selected_prj_name()const
    {
        return this->selected_before_;
    }

private slots:
    void select_project(const QModelIndex&);

signals:
    // プロジェクト名がクリックされたら創出されるシグナル
    void clicked_project_name(const QString&);
};

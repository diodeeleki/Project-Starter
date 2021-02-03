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

#include <QMainWindow>
#include <QString>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui
{ 
	class MainWindowUiRoot; 
}
QT_END_NAMESPACE

class MainWindow
: public QMainWindow
{
    Q_OBJECT

	Ui::MainWindowUiRoot *ui_;

    const QString init_file_path_;
    const QString default_replace_sign_head_;
    const QString default_replace_sign_end_;
    const QString default_wizard_path_;

    QSettings setting_;

public:
    MainWindow(QWidget* = nullptr);
    ~MainWindow();

private:
    // ある文字列で囲まれた文字列抽出
    QStringList search_inside(const QString&, const QString&, const QString&)const noexcept(false);

    // あるフォルダ下全てのフォルダ名とファイル名の置換サイン検索
    QStringList search_sign_name(const QString&)const noexcept(false);

    // あるフォルダ下全てのファイル内の置換サイン検索
    QStringList search_sign_file(const QString&)const noexcept(false);

    // フォルダ下をすべてフォルダ&ファイルを置換&コピー
    void copy_replace_folder(const QString&, const QString&, const QStringList&, const QStringList&)const noexcept(false);

    // ファイル内のテキストを置換
    void replace_file_text(const QString&, const QStringList&, const QStringList&)const noexcept(false);

private slots:
    // acceptボタンが押されたとき呼ばれるスロット
    void clicked_accept();

    // プロジェクトリストが押されたとき呼ばれるスロット
    void clicked_prj_list(const QString&);

    // 設定アクションがクリックされたとき呼び出し
    void clicked_setting();
};

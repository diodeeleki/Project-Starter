#/*--------------------------------------------------------------------------
#
#	Copyright © 2021, Yoshiki Tanaka
#	
#	This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#*///------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.19.1)
project(main_window CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.0.2/gcc_64)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/browse_textbox)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/pro_name_list)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/relpace_view)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/setting_dialog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/progress_bar)

find_package(Qt6 REQUIRED Core)
find_package(Qt6 REQUIRED Widgets)
find_package(Qt6 REQUIRED Sql)

# AUTOUICを使わずuiファイルのパスを手動でUICへ指定
qt_wrap_ui(UI_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/ui/main_window.ui)

# リソース管理ファイル
QT_ADD_RESOURCES(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/etc/etc.qrc)

add_executable(main_window
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/special.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/slots.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/main_window.hpp
    ${UI_HEADERS}
    ${RESOURCES}
)

target_include_directories(main_window PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET main_window PROPERTY CXX_STANDARD 20)
target_link_libraries(main_window PRIVATE Qt6::Core)
target_link_libraries(main_window PRIVATE Qt6::Widgets)
target_link_libraries(main_window PRIVATE Qt6::Sql)

target_link_libraries(main_window PRIVATE browse_textbox)
target_link_libraries(main_window PRIVATE pro_name_list)
target_link_libraries(main_window PRIVATE relpace_view)
target_link_libraries(main_window PRIVATE setting_dialog)
target_link_libraries(main_window PRIVATE progress_bar)

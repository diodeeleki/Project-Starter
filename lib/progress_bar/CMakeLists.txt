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
project(progress_bar CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED Core)
find_package(Qt6 REQUIRED Widgets)
find_package(Qt6 REQUIRED Sql)

# AUTOUICを使わずuiファイルのパスを手動でUICへ指定
qt_wrap_ui(UI_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/ui/progress_bar.ui)

add_library(progress_bar STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/progress_bar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/progress_bar.hpp
    ${UI_HEADERS}
)

target_include_directories(progress_bar PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET progress_bar PROPERTY CXX_STANDARD 20)
target_link_libraries(progress_bar PRIVATE Qt6::Core)
target_link_libraries(progress_bar PRIVATE Qt6::Widgets)
target_link_libraries(progress_bar PRIVATE Qt6::Sql)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

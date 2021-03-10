cmake_minimum_required(VERSION 3.5)

project(__$project_name$___test CXX)

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.0.2/gcc_64)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(__$project_name$___test ./main.cpp)

target_link_libraries(__$project_name$___test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(__$project_name$___test PRIVATE __$project_name$__)

set_property(TARGET __$project_name$___test PROPERTY CXX_STANDARD 20)

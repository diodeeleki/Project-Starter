cmake_minimum_required(VERSION 3.5)
project(__$project_name$__ CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.0.2/gcc_64)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# リソース管理ファイル指定
QT_ADD_RESOURCES(RESOURCES 
    ./resource/resource.qrc
)

# ソースファイル指定
add_library(__$project_name$__ STATIC 
    ./src/__$project_name$__.cpp
    ./include/__$project_name$__.hpp
    ${UI_HEADERS}   
    ${RESOURCES}
)

target_include_directories(__$project_name$__ PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(__$project_name$__ PUBLIC ./include)
target_link_libraries(__$project_name$__ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_property(TARGET __$project_name$__ PROPERTY CXX_STANDARD 20)

add_subdirectory(./test)

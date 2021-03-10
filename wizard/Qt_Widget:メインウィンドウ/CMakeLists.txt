cmake_minimum_required(VERSION 3.5)

project(__$project_name$__ CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.0.2/gcc_64)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/)

# uiファイル指定
qt_wrap_ui(UI_HEADERS 
    ./ui/__$project_name$__.ui
)

# リソース管理ファイル指定
QT_ADD_RESOURCES(RESOURCES 
    ./resource/resource.qrc
)

# ソースファイル指定
set(PROJECT_SOURCES
    ./src/main.cpp
    ./src/__$project_name$__.cpp
    ./include/__$project_name$__.hpp
    ${UI_HEADERS}   
    ${RESOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(__$project_name$__ ${PROJECT_SOURCES})
else()
    if(ANDROID)
        add_library(__$project_name$__ SHARED ${PROJECT_SOURCES})
    else()
        add_executable(__$project_name$__ ${PROJECT_SOURCES})
    endif()
endif()

target_include_directories(__$project_name$__ PRIVATE ./include)
target_link_libraries(__$project_name$__ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_property(TARGET __$project_name$__ PROPERTY CXX_STANDARD 20)

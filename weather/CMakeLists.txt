cmake_minimum_required(VERSION 3.2)

project(MainProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)  # 启用自动 UI 编译
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.h
        weatherdata.h
        weathertool.h
        mainwidget.h
        mainwindow.cpp
        weathertool.cpp
        mainwidget.cpp
        main.qrc
        mainwindow.ui
        mainwidget.ui
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt6 COMPONENTS Network REQUIRED)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(weather
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(weather SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(weather
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(weather PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Network)

set_target_properties(weather PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS weather
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(weather)
endif()

add_definitions(-DPRO_FILE_PWD="${CMAKE_SOURCE_DIR}")

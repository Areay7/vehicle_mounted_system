cmake_minimum_required(VERSION 3.2)

project(MainProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets Mqtt Network REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    weatherdata.h
    weathertool.h
    mainwidget.h

    weathertool.cpp
    mainwidget.cpp
    mainwidget.ui
    currentsituation.h
    currentsituation.cpp
    currentsituation.ui
    main.qrc
)

if(Qt6_FOUND)
    qt_add_executable(MyMqttTest
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(MyMqttTest SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MyMqttTest
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MyMqttTest PRIVATE Qt6::Widgets Qt6::Mqtt Qt6::Network)

set_target_properties(MyMqttTest PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

install(TARGETS MyMqttTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(Qt6_FOUND)
    qt_finalize_executable(MyMqttTest)
endif()

add_definitions(-DPRO_FILE_PWD="${CMAKE_SOURCE_DIR}")

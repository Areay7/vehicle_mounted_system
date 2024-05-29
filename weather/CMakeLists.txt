cmake_minimum_required(VERSION 3.2)

project(Viches VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt components including WebEngineWidgets
find_package(Qt6 COMPONENTS Widgets Mqtt Network WebEngineWidgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    controlwidget.h
    weatherdata.h
    weathertool.h
    mainwidget.h
    wifilistwidget.h
    controlwidget.cpp
    weathertool.cpp
    mainwidget.cpp
    mainwidget.ui
    currentsituation.h
    mqttlink.h
    sysdatatype.h
    http.h
    http.cpp
    currentsituation.cpp
    wifilistwidget.cpp
    mqttlink.cpp
    currentsituation.ui
    environmentwidget.ui
    controlwidget.ui
    wifilistwidget.ui
    systemtime.ui
    musicwidget.ui
    main.qrc
    control.qrc
    mainpage.qrc
    musicPlayer//musicPlayer.qrc
    remote/remotecontrol.cpp
    remote/remotecontrol.h
    remote/remotecontrol.ui
    remote/remoteview.cpp
    remote/remoteview.h
    remote/remoteview.ui
    remoteRes.qrc
    record.h
    record.cpp
    specch.h
    specch.cpp
)

if(Qt6_FOUND)
    qt_add_executable(MainProject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(MainProject SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MainProject
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(MainProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MainProject PRIVATE Qt6::Widgets Qt6::Mqtt Qt6::Network Qt6::WebEngineWidgets)

set_target_properties(MainProject PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

install(TARGETS MainProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(Qt6_FOUND)
    qt_finalize_executable(MainProject)
endif()

add_definitions(-DPRO_FILE_PWD="${CMAKE_SOURCE_DIR}")

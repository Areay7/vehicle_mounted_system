#/***************************************************************
#*   @project         Viches
#*   @file            CMakeLists.txt
#*   @brief           Abstract
#*   @author          Areay7
#*   @emial           2507549477@qq.com
#*   @blog            www.myblog.areay7.cn
#*   @date            2024-07-01
#*   @Copyright:      Copyright (c) 2024 MQ. All rights reserved.
#****************************************************************/



cmake_minimum_required(VERSION 3.2)

project(Viches VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt components including WebEngineWidgets
find_package(Qt6 COMPONENTS Widgets Mqtt Network WebEngineWidgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

file(GLOB_RECURSE HEAD_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE CPP_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE UI_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE SROUCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
)

set(PROJECT_SOURCES ${HEAD_FILE} ${CPP_FILE} ${UI_FILE} ${SROUCE_FILE})


if(Qt6_FOUND)
    qt_add_executable(Viches
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        # musicwidget.ui musicwindow.cpp musicwindow.h musicwindow.o musicwindow.ui
        # battery.ui
        # battery.h battery.cpp
    )
else()
    if(ANDROID)
        add_library(Viches SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Viches
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(Viches PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Viches PRIVATE Qt6::Widgets Qt6::Mqtt Qt6::Network Qt6::Multimedia Qt6::WebEngineWidgets)


add_definitions(-DPRO_FILE_PWD="${CMAKE_SOURCE_DIR}")
# add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x060000)

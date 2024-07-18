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

file(GLOB_RECURSE HEAD_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE CPP_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE UI_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE SROUCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

set(PROJECT_SOURCES ${HEAD_FILE} ${CPP_FILE} ${UI_FILE} ${SROUCE_FILE})


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

# set_target_properties(MainProject PROPERTIES
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
# )

# install(TARGETS MainProject
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )

# if(Qt6_FOUND)
#     qt_finalize_executable(MainProject)
# endif()

add_definitions(-DPRO_FILE_PWD="${CMAKE_SOURCE_DIR}")

#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

cmake_minimum_required(VERSION 3.15)

project(Chess DESCRIPTION "Yet another chess implementation for excercise purposes" HOMEPAGE_URL "https://github.com/antlampas/Chess" LANGUAGES "CXX")

string(TOUPPER "${LIBRARIES_LINKING}" LIBRARIES_LINKING)

if("${LIBRARIES_LINKING}" NOT MATCHES "SHARED" OR "${LIBRARIES_LINKING}" NOT MATCHES "STATIC")
set(LIBRARIES_LINKING "")
endif()

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

if("${TEST}" MATCHES "Test")
    add_definitions(-DDEBUG)
    add_definitions(-DTESTING)
endif()

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})
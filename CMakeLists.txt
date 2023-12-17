#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

cmake_minimum_required(VERSION 3.15)

project(Chess DESCRIPTION "Yet another chess implementation for excercise purposes" HOMEPAGE_URL "https://github.com/antlampas/Chess" LANGUAGES "CXX")

string(TOUPPER "${LIBRARIES_LINKING}" LIBRARIES_LINKING)
string(TOUPPER "${TESTING}" TESTING)
string(TOUPPER "${RELEASETYPE}" RELEASETYPE)

if((NOT ("${LIBRARIES_LINKING}" MATCHES "SHARED")) OR (NOT ("${LIBRARIES_LINKING}" MATCHES "STATIC")))
set(LIBRARIES_LINKING "")
endif()


if("${RELEASETYPE}" MATCHES "DEBUG")
    add_definitions(-DDEBUG)
endif()

if(TESTBOARD)
    add_definitions(-DTESTBOARD)
endif()

if(TESTTIMER)
    add_definitions(-DTESTTIMER)
endif()
if(TESTTURNMANAGER)
    add_definitions(-DTESTTURNMANAGER)
endif()

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})
#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

cmake_minimum_required(VERSION 3.15)

project(Chess)

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

if("${TEST}" MATCHES "Test")
    add_definitions(-DTESTING)
endif()

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})
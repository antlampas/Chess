#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

cmake_minimum_required(VERSION 3.15)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif (NOT CMAKE_BUILD_TYPE)

project(Chess)

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})
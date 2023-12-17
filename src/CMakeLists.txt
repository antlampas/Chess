#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_subdirectory(board board)
add_subdirectory(turnManager turnManager)

if(DEFINED TESTBOARD OR DEFINED TESTTIMER OR DEFINED TESTTURNMANAGER)
set(TESTSLIBRARY "tests")
endif()

add_executable(chess main.cpp)

target_link_libraries(chess PUBLIC board turnManager)
#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

if(DEFINED TESTBOARD)
set(TESTBOARD "")
endif()
if(DEFINED TESTTIMER "")
set(TESTTIMER)
endif()
if(DEFINED TESTTURNMANAGER "")
set(TESTTURNMANAGER)
endif()

if(DEFINED TESTBOARD OR DEFINED TESTTIMER OR DEFINED TESTTURNMANAGER)
add_subdirectory(tests tests)
endif()

add_subdirectory(board board)
add_subdirectory(timer timer)
add_subdirectory(turnManager turnManager)

add_executable(chess main.cpp)

target_link_libraries(chess PUBLIC board turnManager timer)
#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_subdirectory(board board)
add_subdirectory(turnManager turnManager)
add_executable(chess main.cpp)


if(TEST)
add_subdirectory(tests tests)
endif()

target_link_libraries(chess PUBLIC board turnManager)
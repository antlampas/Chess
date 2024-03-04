#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

#get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_subdirectory(board board)
add_subdirectory(timer timer)
add_subdirectory(turnManager turnManager)

add_dependencies(timer turnManager)

add_executable(chess main.cpp)

target_link_libraries(chess PUBLIC
                        board
                        timer
                        turnManager
                    )
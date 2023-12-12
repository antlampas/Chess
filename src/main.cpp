/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif
#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

int main(int argc,char** argv)
{
    board b;
    turnManager& tm = turnManager::getInstance(b);

    boardMapType board = b.boardStatus();
    std::for_each(board.begin(),board.end(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){std::cout << column << " ";});std::cout << std::endl;});
    std::cout << std::endl << std::endl;
    tm.move("a1");
    return 0;
}
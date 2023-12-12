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
    turnManager& tm1 = turnManager::getInstance();
    boardMapType board = tm1.b.boardStatus();
    std::for_each(board.rbegin(),board.rend(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){(column!="e")?(std::cout << column << " "):(std::cout << column << "  ");});std::cout << std::endl;});
    std::cout << std::endl << std::endl;
    tm1.move("d2","d3");
    tm1.move("d7","d6");
    board = tm1.b.boardStatus();
    std::for_each(board.rbegin(),board.rend(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){(column!="e")?(std::cout << column << " "):(std::cout << column << "  ");});std::cout << std::endl;});
    
    return 0;
}
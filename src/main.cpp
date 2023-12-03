/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <algorithm>
#include <iostream>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

int main(int argc,char** argv)
{
    board b;
    std::vector<std::vector<std::string>> board = b.boardStatus();
    std::for_each(board.begin(),board.end(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){std::cout << column << " ";});std::cout << std::endl;});
    return 0;
}
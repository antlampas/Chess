#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::vector<std::vector<std::string>> board::boardStatus()
{
    std::vector<std::vector<std::string>> board = this->boardMap;

    return board;
}
#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::pair<char,char> board::decodePieceName(std::string piece)
{
    if(this->isPieceNameValid(piece))
        return std::make_pair(piece.at(0),piece.at(1));
    else
        return std::pair<char,char>();
}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::pair<char,char> board::decodePieceName(std::string piece)
{
    this->functionsState.decodePieceName = 1;
    if(this->isPieceNameValid(piece))
    {
        this->functionsState.decodePieceName = 0;

        return std::make_pair(piece.at(0),piece.at(1));
    }
    else
    {
        this->functionsState.decodePieceName = 0;

        return std::pair<char,char>();
    }
}
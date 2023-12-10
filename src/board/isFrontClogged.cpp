/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

inline bool board::isFrontClogged(std::string position)
{
    std::pair<int,int> decodedCoordinates = this->decodeCoordinates(position);
    
    const int& row    {decodedCoordinates.first};
    const int& column {decodedCoordinates.second};

    if(this->boardMap.at(row+1).at(column)!="e")
        return true;
    else
        return false;
}
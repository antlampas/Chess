#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isFrontClogged(std::string position)
{
    std::pair<int,int> decodedCoordinates = this->decodeCoordinates(position);
    
    const int& row    {decodedCoordinates.first};
    const int& column {decodedCoordinates.second};

    if(this->boardMap.at(row+1).at(column)!="e")
        return true;
    else
        return false;
}
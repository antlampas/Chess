#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::string board::getPieceInSquare(std::string coordinates)
{
    std::pair<int,int> decodedCoordinates = this->decodeCoordinates(coordinates);
    
    const int& row    {decodedCoordinates.first};
    const int& column {decodedCoordinates.second};
    if(row != -1)
        return this->boardMap.at(row).at(column);
    else
        this->error = "Failed to get the piece at given coordinates";
    return std::string();
}
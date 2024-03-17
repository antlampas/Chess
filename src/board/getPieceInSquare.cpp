/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::string board::getPieceInSquare(std::string coordinates)
{
    this->functionsState.getPieceInSquare = 1;

    std::pair<int,int> decodedCoordinates = this->decodeCoordinates(coordinates);
    
    const int& row    {decodedCoordinates.first};
    const int& column {decodedCoordinates.second};

    this->functionsState.getPieceInSquare = 2;

    if(row != -1)
        return this->boardMap.at(row).at(column);
    else
        this->error = "Failed to get the piece at given coordinates";

    this->functionsState.getPieceInSquare = 0;
    
    return std::string();
}
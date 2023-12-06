/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::vector<std::string> board::listValidMoves(std::string coordinates)
{
    std::pair<int,int> decodedCoordinates = this->decodeCoordinates(coordinates);

    const int& row    {decodedCoordinates.first};
    const int& column {decodedCoordinates.second};
    
    const std::string& piece = this->getPieceInSquare(coordinates);
    char p = 'e';
    
    if(this->isPieceNameValid(piece))
          p = piece.at(1); 
    else
        return std::vector<std::string>();
}
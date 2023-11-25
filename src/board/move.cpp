/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::move(std::string start,std::string end)
{
    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);
    
    const int& startColumn {decodedStartCoordinates.first};
    const int& startRow    {decodedStartCoordinates.second};
    const int& endColumn   {decodedEndCoordinates.first};
    const int& endRow      {decodedEndCoordinates.second};

    std::string movingPiece = this->getPieceInSquare(start);
    // if(this->isMoveValid(start,end))
    // {
        
    // }
    return true;
}
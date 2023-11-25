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
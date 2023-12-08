/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
#include <iostream>
#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::move(std::string start,std::string end)
{
    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);
    
    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    std::string movingPiece = this->getPieceInSquare(start);
    std::string targetPiece = this->getPieceInSquare(end);
    if(this->isMoveValid(start,end))
        if(!this->isMoveClogged(start,end))
        {
            if(targetPiece != "e")
                if(targetPiece.at(0) != movingPiece.at(0))
                    this->tookPieces.push_back(targetPiece);
                else
                    return false;
            else
            {
                this->boardMap.at(endRow).at(endColumn) = movingPiece;
                this->boardMap.at(startRow).at(startColumn) = "e";

                return true;
            }
        }
        else
            return false;
    else
        return false;
}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isMoveClogged(std::string start,std::string end)
{
    std::pair<int,int> decodedStartCoordinates {this->decodeCoordinates(start)};
    std::pair<int,int> decodedEndCoordinates   {this->decodeCoordinates(end)};

    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    std::string piece {this->getPieceInSquare(start)};
    if(piece!="e")
        if(piece.at(1)=='p')
            if(this->isFrontClogged(start))
                return true;
            else
                return false;
        else if(piece.at(1)=='r')
            if( ((startRow == endRow) && (startColumn != endColumn) && (this->isColumnClogged(start,end))) || ((startColumn == endColumn) && (startRow != endRow) && (this->isRowClogged(start,end))) )
                return true;
            else
                return false;
        else if(piece.at(1)=='n')
            return false;
        else if(piece.at(1)=='b')
            if(this->isDiagonalClogged(start,end))
                return true;
            else
                return false;
        else if(piece.at(1)=='q')
            if(this->isColumnClogged(start,end) || this->isRowClogged(start,end) || this->isDiagonalClogged(start,end))
                return true;
            else
                return false;
        else if(piece.at(1)=='k')
            return false;
    else
    {
        this->error = "No pieces on the square";
        return false;
    }
}
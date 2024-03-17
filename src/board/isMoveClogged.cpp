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
    this->functionsState.isMoveClogged = 0;

    std::pair<int,int> decodedStartCoordinates {this->decodeCoordinates(start)};
    std::pair<int,int> decodedEndCoordinates   {this->decodeCoordinates(end)};

    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    std::string piece {this->getPieceInSquare(start)};

    this->functionsState.isMoveClogged = 1;

    if(piece!="e")
    {
        if(piece.at(1)=='p')
        {
            this->functionsState.isMoveClogged = 0;
            if(((startRow != endRow) && (startColumn == endColumn)) && this->isFrontClogged(start,end))
                return true;
            if(((startRow != endRow) && (startColumn == endColumn)) && (this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            return false;
        }
        else if(piece.at(1)=='r')
        {
            this->functionsState.isMoveClogged = 0;
            if(((startRow == endRow) && (startColumn != endColumn) && (this->isColumnClogged(start,end))) || ((startColumn == endColumn) && (startRow != endRow) && (this->isRowClogged(start,end))))
                return true;
            if((this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            return false;
        }
        else if(piece.at(1)=='n')
        {
            this->functionsState.isMoveClogged = 0;
            if((this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            return false;
        }
        else if(piece.at(1)=='b')
        {
            this->functionsState.isMoveClogged = 0;
            if(this->isDiagonalClogged(start,end))
                return true;
            if((this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            return false;
        }
        else if(piece.at(1)=='q')
        {
            this->functionsState.isMoveClogged = 0;
            if(this->isColumnClogged(start,end) || this->isRowClogged(start,end) || this->isDiagonalClogged(start,end))
                return true;
            if((this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            return false;
        }
        else if(piece.at(1)=='k')
        {
            this->functionsState.isMoveClogged = 0;
            if((this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            if((this->boardMap.at(endRow).at(endColumn) != "e") && (this->boardMap.at(endRow).at(endColumn).at(0) == piece.at(0)))
                return true;
            return false;
        }
        return false;
    }
    else
    {
        this->error = "No pieces on the square";
        this->functionsState.isMoveClogged = 0;
        return false;
    }
}
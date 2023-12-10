/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <regex>
#include <cmath>


#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isMoveValid(std::string start,std::string end)
{
    std::string piece {this->getPieceInSquare(start)};

    if(this->isPieceNameValid(piece) && this->isCoordinateValid(start) && this->isCoordinateValid(end))
    {
        std::pair<int,int> startCoordinates = this->decodeCoordinates(start);
        std::pair<int,int> endCoordinates   = this->decodeCoordinates(end);
        
        const int& startRow    {startCoordinates.first};
        const int& startColumn {startCoordinates.second};
        const int& endRow      {endCoordinates.first};
        const int& endColumn   {endCoordinates.second};
        
        bool advanceOne   = ((startColumn == endColumn) && ((endRow - startRow) == 1));
        bool pawnCapture  = ((std::abs(endColumn-startColumn)==1) && ((endRow-startRow)==1));
        bool moveHV       = (!((startColumn != endColumn) && (startRow == endRow)) != !((startColumn == endColumn) && (startRow != endRow)));
        bool moveDiagonal = (std::abs(endRow-startRow) == std::abs(endColumn-startColumn));
        bool moveAnywhere = (!moveHV != !moveDiagonal);
        bool moveOne      = ((std::abs(endRow-startRow) == 1) || (std::abs(endColumn-startColumn) == 1));
        bool moveL        = (!((std::abs(endRow-startRow) == 1) && (std::abs(endColumn-startColumn) == 2)) != !((std::abs(endRow-startRow) == 2) && (std::abs(endColumn-startColumn) == 1)));
        bool noMove       = ((startRow == endRow) && (startColumn == endColumn));
        
        if(piece.at(1) == 'p')      return (noMove || advanceOne || pawnCapture);
        else if(piece.at(1) == 'r') return (noMove || moveHV);
        else if(piece.at(1) == 'n') return (noMove || moveL);
        else if(piece.at(1) == 'b') return (noMove || moveDiagonal);
        else if(piece.at(1) == 'q') return (noMove || moveAnywhere);
        else if(piece.at(1) == 'k') return (noMove || moveOne);
        else
        {
            this->error = "Move validation: something went wrong...";
            return false;
        }
    }
    else
    {
        this->error = "Move validation failed";
        return false;
    }
}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

int board::lowerColumnFreeSquare(int row,int column,std::string previousRow,std::string piece)
{
    this->functionsState.lowerColumnFreeSquare = 1;

    int endRow = 0;
    while(this->isColumnClogged(this->encodeCoordinates(std::pair<int,int>(endRow,column)),previousRow) && (endRow < row) ) ++endRow;
    if(this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(endRow,column))).at(0) == piece.at(0)) ++endRow;

    this->functionsState.lowerColumnFreeSquare = 0;
    
    return endRow;
}


/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

int board::upperColumnFreeSquare(int row,int column,std::string nextRow,std::string piece)
{
    int endRow = 7;
    while(this->isColumnClogged(nextRow,this->encodeCoordinates(std::pair<int,int>(endRow,column))) && (endRow > row) ) --endRow;
    if(this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(endRow,column))).at(0) == piece.at(0)) --endRow;

    return endRow;
}
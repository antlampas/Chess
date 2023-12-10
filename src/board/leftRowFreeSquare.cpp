/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

int board::leftRowFreeSquare(int row,int column,std::string previousColumn,std::string piece)
{
    int endColumn = 0;
    while(this->isColumnClogged(this->encodeCoordinates(std::pair<int,int>(row,endColumn)),previousColumn) && (endColumn < column) ) ++endColumn;
    if(this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row,endColumn))).at(0) == piece.at(0)) ++endColumn;

    return endColumn;
}
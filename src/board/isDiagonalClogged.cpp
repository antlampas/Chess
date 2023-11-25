/*
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <cmath>
#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isDiagonalClogged(std::string start,std::string end)
{
    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);

    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    if(std::abs(endColumn - startColumn) == std::abs(endRow - startRow))
        if((endColumn > startColumn) && (endRow > startRow))
            for(int i=(startRow+1);i<endRow;i++)
                if(this->boardMap.at(i).at(i)!="e")
                    return true;
        else if( (endColumn < startColumn) && (endRow < startRow) )
            for(int i=(startRow-1);i>endRow;i--)
                if(this->boardMap.at(i).at(i)!="e")
                    return true;
        else if( (endColumn > startColumn) && (endRow < startRow) )
            for(int i=(startRow-1),j=(startColumn+1);i>endRow,j<endColumn;i--,j++)
                if(this->boardMap.at(i).at(j)!="e")
                    return true;
        else if( (endColumn < startColumn) && (endRow > startRow) )
            for(int i=(startRow+1),j=(startColumn-1);i<endRow,j>endColumn;i++,j--)
                if(this->boardMap.at(i).at(j)!="e")
                    return true;
    else
        this->error = "Not on a diagonal";
    return false;
}
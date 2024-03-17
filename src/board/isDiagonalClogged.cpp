/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <iostream>
#include <cmath>
#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isDiagonalClogged(std::string start,std::string end)
{
    this->functionsState.isDiagonalClogged = 1;

    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);

    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    this->functionsState.isDiagonalClogged = 2;

    if(std::abs(endColumn - startColumn) == std::abs(endRow - startRow))
        if((endRow > startRow) && (endColumn > startColumn))      //Check main diagonal to the right
            for(int i=(startRow+1),j=(startColumn+1);i<endRow,j<endColumn;i++,j++)
                if(this->boardMap.at(i).at(j)!="e")
                    return true;
        else if((endRow < startRow) && (endColumn < startColumn)) //Check main diagonal to the left
            for(int i=(startRow-1),j=(startColumn-1);i>endRow,j>endColumn;i--,j--)
                if(this->boardMap.at(i).at(j)!="e")
                    return true;
        else if((endRow < startRow) && (endColumn > startColumn)) //Check secondary diagonal to the right
            for(int i=(startRow-1),j=(startColumn+1);i>endRow,j<endColumn;i--,j++)
                if(this->boardMap.at(i).at(j)!="e")
                    return true;
        else if((endRow > startRow) && (endColumn < startColumn)) //Check secondary diagonal to the left
            for(int i=(startRow+1),j=(startColumn-1);i<endRow,j>endColumn;i++,j--)
                if(this->boardMap.at(i).at(j)!="e")
                    return true;
    else
        this->error = "Not on a diagonal";

    this->functionsState.isDiagonalClogged = 0;
    
    return false;
}
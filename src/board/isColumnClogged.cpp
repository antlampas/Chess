/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isColumnClogged(std::string start,std::string end)
{
    this->functionsState.isColumnClogged = 1;

    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);
    
    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    bool clogged = false;
    
    this->functionsState.isColumnClogged = 2;

    if(startColumn == endColumn)
        for(int i=startRow+1;i<endRow;i++)
            if(this->boardMap.at(i).at(startColumn) != "e")
                clogged = true;
    else
        this->error = "Not on the same column";

    this->functionsState.isColumnClogged = 0;
    
    return clogged;
}
#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isRowClogged(std::string start,std::string end)
{
    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);
    
    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    bool clogged = false;
    if(startRow == endRow)
        std::for_each(this->boardMap.at(startRow).begin(),this->boardMap.at(startRow).end(),[&clogged](std::string column){if(column!="e") clogged = true;});
    else
        this->error = "Not on the same Row";
    return clogged;
}
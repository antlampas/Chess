#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isColumnClogged(std::string start,std::string end)
{
    std::pair<int,int> decodedStartCoordinates = this->decodeCoordinates(start);
    std::pair<int,int> decodedEndCoordinates   = this->decodeCoordinates(end);
    
    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};
    const int& endRow      {decodedEndCoordinates.first};
    const int& endColumn   {decodedEndCoordinates.second};

    bool clogged = false;
    if(startColumn == endColumn)
        std::for_each(this->boardMap.begin(),this->boardMap.end(),[&clogged,startColumn](std::vector<std::string> row){if(row.at(startColumn)!="e") clogged = true;});
    else
        this->error = "Not on the same column";
    return clogged;
}
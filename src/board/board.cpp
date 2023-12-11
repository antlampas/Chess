/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <algorithm>
#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

board::board()
{
    std::for_each(this->boardMap.begin(),this->boardMap.end(),[](std::vector<std::string> column){std::fill(column.begin(),column.end(),"e");});

    const std::vector<std::string> backLine {"r","n","b","q","k","b","n","r"};

    for(int row: {0,1,2,3,4,5,6,7})
        if(row==0)
            for(int column: {0,1,2,3,4,5,6,7})
                this->boardMap.at(row).at(column) = "w"+backLine.at(column);
        else if(row==7)
            for(int column: {0,1,2,3,4,5,6,7})
                this->boardMap.at(row).at(column) = "b"+backLine.at(column);
        else if(row==1)
            for(int column: {0,1,2,3,4,5,6,7})
                this->boardMap.at(row).at(column) = "wp";
        else if(row==6)
            for(int column: {0,1,2,3,4,5,6,7})
                this->boardMap.at(row).at(column) = "bp";
}

board::board(boardMapType initialPositions)
{
    std::regex pieceNameFormat("^[wb][prnbkq]$|^e$");
    
    bool validInput = true;

    for(auto row: initialPositions)
    {
        for(auto column: row)
            if(!std::regex_match(column,pieceNameFormat))
            {
                validInput = false;
                break;
            }
        if(!validInput)
        {
            std::for_each(this->boardMap.begin(),this->boardMap.end(),[](columnType column){std::fill(column.begin(),column.end(),"e");});
            return;
        }
    }

    std::swap(this->boardMap,initialPositions);
}
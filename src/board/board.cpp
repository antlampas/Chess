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
    const std::vector<std::string> whiteBackLine  {"wr","wn","wb","wq","wk","wb","wn","wr"};
    const std::vector<std::string> blackBackLine  {"br","bn","bb","bq","bk","bb","bn","br"};
    const std::vector<std::string> whitePawnLine  {"wp","wp","wp","wp","wp","wp","wp","wp"};
    const std::vector<std::string> blackPawnLine  {"bp","bp","bp","bp","bp","bp","bp","bp"};
    const std::vector<std::string> emptyLine      {"e", "e", "e", "e", "e", "e", "e", "e" };

    std::for_each(this->boardMap.begin(),this->boardMap.end(),[emptyLine](std::vector<std::string> column){std::copy(emptyLine.begin(),emptyLine.end(),column.begin());});
    
    for(int row: {0,1,2,3,4,5,6,7})
    {
        if(row==0)      std::copy(whiteBackLine.begin(),whiteBackLine.end(),this->boardMap.at(row).begin());
        else if(row==7) std::copy(blackBackLine.begin(),blackBackLine.end(),this->boardMap.at(row).begin());
        else if(row==1) std::copy(whitePawnLine.begin(),whitePawnLine.end(),this->boardMap.at(row).begin());
        else if(row==6) std::copy(blackPawnLine.begin(),blackPawnLine.end(),this->boardMap.at(row).begin());
        else            std::copy(emptyLine.begin(),emptyLine.end(),this->boardMap.at(row).begin());
    }
}

board::board(boardMapType initialPositions)
{
    std::regex pieceNameFormat("^[wb][prnbkq]$|^e$");
    
    const std::vector<std::string> emptyLine {"e","e","e","e","e","e","e","e"};

    bool validInput = true;

    for(auto row: initialPositions)
        for(auto column: row)
            if(!std::regex_match(column,pieceNameFormat))
                validInput = false;

    if(validInput)
        std::copy(initialPositions.begin(),initialPositions.end(),this->boardMap.begin());
    else
        std::for_each(this->boardMap.begin(),this->boardMap.end(),[emptyLine](columnType column){std::copy(emptyLine.begin(),emptyLine.end(),column.begin());});
}
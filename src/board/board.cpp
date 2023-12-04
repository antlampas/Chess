/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

board::board()
{
    std::for_each(this->boardMap.begin(),this->boardMap.end(),[](std::vector<std::string> column){std::fill(column.begin(),column.end(),"e");});

    const std::vector<std::string> backLine {"r","n","b","q","k","b","n","r"};

    for(int row: {0,1,2,3,4,5,6,7})
        if(row==0)
            for(int column=0;column<8;column++)
            {
                this->boardMap.at(row).at(column) = backLine.at(column);
                this->boardMap.at(row).at(column).insert(0,"w");
            }
        else if(row==7)
            for(int column=0;column<8;column++)
            {
                this->boardMap.at(row).at(column) = backLine.at(column);
                this->boardMap.at(row).at(column).insert(0,"b");
            }
        else if(row==1)
            for(int column=0;column<8;column++)
                this->boardMap.at(row).at(column) = "wp";
        else if(row==6)
            for(int column=0;column<8;column++)
                this->boardMap.at(row).at(column) = "bp";
}
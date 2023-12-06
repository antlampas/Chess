/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <string>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::string encodeCoordinates(std::pair<int,int> coordinates)
{
    if(coordinates.first > -1 && coordinates.first < 9)
        if(coordinates.second > -1 && coordinates.second < 9)
        {
            const char row    = coordinates.first  + 49;
            const char column = coordinates.second + 97;
            
            std::string encodedCoordinates;
            
            encodedCoordinates.append(1,column).append(1,row);

            return encodedCoordinates;
        }
    return std::string();
}
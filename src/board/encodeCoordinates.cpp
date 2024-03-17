/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <string>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::string board::encodeCoordinates(std::pair<int,int> coordinates)
{
    this->functionsState.encodeCoordinates = 1;
    if((coordinates.first > -1 && coordinates.first < 8) && (coordinates.second > -1 && coordinates.second < 8))
    {
        this->functionsState.encodeCoordinates = 2;
        const char row    = coordinates.first  + 49;
        const char column = coordinates.second + 97;
        
        std::string encodedCoordinates;
        
        encodedCoordinates.append(1,column).append(1,row);

        this->functionsState.encodeCoordinates = 0;

        return encodedCoordinates;
    }

    this->functionsState.encodeCoordinates = 0;
    
    return std::string();
}
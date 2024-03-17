/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isCoordinateValid(std::string coordinates)
{
    this->functionsState.isCoordinateValid = 1;

    std::regex coordinatesFormat("^[a-h][1-8]$");
    
    this->functionsState.isCoordinateValid = 0;
    
    return std::regex_match(coordinates,coordinatesFormat);
}
#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isCoordinateValid(std::string coordinates)
{
    std::regex coordinatesFormat("^[abcdefg][12345678]$");
    
    return std::regex_match(coordinates,coordinatesFormat);
}
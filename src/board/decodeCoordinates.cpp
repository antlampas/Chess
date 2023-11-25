#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::pair<int,int> board::decodeCoordinates(std::string coordinates)
{
    std::pair<int,int> decodedCoordinates {-1,-1};

    if(this->isCoordinateValid(coordinates))
    {
        decodedCoordinates.first  = coordinates.at(1) - 48;
        decodedCoordinates.second = coordinates.at(0) - 97;
    }
    else
        this->error = "Coordinates not valid";
    return decodedCoordinates;
}
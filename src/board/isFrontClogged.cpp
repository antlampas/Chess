/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isFrontClogged(coordinatesType startCoordinates,coordinatesType endCoordinates)
{
    decodedCoordinatesType decodedStartCoordinates = this->decodeCoordinates(startCoordinates);
    decodedCoordinatesType decodedEndCoordinates = this->decodeCoordinates(endCoordinates);
    
    const int& startRow    {decodedStartCoordinates.first};
    const int& startColumn {decodedStartCoordinates.second};

    const int& endRow    {decodedEndCoordinates.first};
    const int& endColumn {decodedEndCoordinates.second};

    if((std::abs(endRow-startRow) == 1) && (endColumn == startColumn))
        if((this->boardMap.at(endRow).at(endColumn)!="e"))
            return true;
    return false;
}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <iostream>
#include <algorithm>
#include <regex>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

bool turnManager::move(coordinatesType startCoordinates,coordinatesType endCoordinates)
{
    std::regex coordinatesFormat("^[a-h][1-8]$");
    std::regex nameFormat("^[wb][prnbkq]$|^e$");

    char currentTeam = this->team;

    boardMapType board = this->b.boardStatus();
    
    if(std::regex_match(startCoordinates,coordinatesFormat) && std::regex_match(endCoordinates,coordinatesFormat))
    {
        decodedCoordinatesType decodedStartCoordinates {-1,-1};
        decodedCoordinatesType decodedEndCoordinates {-1,-1};

        decodedStartCoordinates.second = startCoordinates.at(0) - 97;
        decodedStartCoordinates.first  = startCoordinates.at(1) - 49;
        decodedEndCoordinates.second = endCoordinates.at(0) - 97;
        decodedEndCoordinates.first  = endCoordinates.at(1) - 49;

        pieceType piece = board.at(decodedStartCoordinates.first).at(decodedStartCoordinates.second);

        if(piece.at(0) != 'e')
            if(piece.at(0) == this->team)
                if(this->b.move(startCoordinates,endCoordinates))
                {
                    this->toggleTurn();
                    currentTeam = this->team;
                }
                else
                    std::cout << "Wrong move" << std::endl << std::endl << std::endl << std::endl;
            else
                std::cout << "Not your turn" << std::endl << std::endl << std::endl << std::endl;
        else
            std::cout << "Empty square" << std::endl << std::endl << std::endl << std::endl;
    }

    return true;
}
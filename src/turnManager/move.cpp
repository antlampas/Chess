/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <iostream>
#include <algorithm>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

bool turnManager::move(coordinatesType startCoordinates,coordinatesType endCoordinates)
{
    boardMapType board = this->b.boardStatus();
    
    std::for_each(board.begin(),board.end(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){std::cout << column << " ";});std::cout << std::endl;});
    
    return true;
}
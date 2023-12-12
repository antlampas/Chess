/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <stdexcept>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

void turnManager::setTurn(char team)
{
    if(team == 'w' || team == 'b')
        this->team = team;
    else
        throw std::invalid_argument("Invalid team");

}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <regex>
#include <stdexcept>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

void turnManager::toggleTurn(turnManager *obj)
{
    if(obj->team == 'w') 
        obj->team = 'b';
    else if(this->team == 'b')
        obj->team = 'w';
    else
        throw std::invalid_argument("Invalid team");
}
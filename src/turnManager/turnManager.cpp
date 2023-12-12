/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <utility>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

turnManager::turnManager(boardMapType boardMap)
{
    board b(boardMap);
    this->b = std::move(b);
    this->setTurn('w');
}

turnManager::turnManager()
{
    board b;
    this->b = std::move(b);
    this->setTurn('w');
}
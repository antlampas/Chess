/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

turnManager& turnManager::getInstance(board& b)
{
    static turnManager instance(b);
    return instance;
}
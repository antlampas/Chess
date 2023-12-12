/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TURNMANAGER_HPP
#define TURNMANAGER_HPP

#include "board.hpp"

#ifdef DEBUG
    #define private public
#endif

class turnManager
{
    private:
    board* b;
    turnManager(board&);
    static turnManager* instance;
    bool team; //true: white; false: black
    
    public:
    turnManager()                         = delete;
    turnManager(turnManager&)             = delete;
    turnManager(turnManager&&)            = delete;
    turnManager& operator=(turnManager&)  = delete;
    turnManager& operator=(turnManager&&) = delete;
    static turnManager& getInstance(board&);
    bool move(coordinatesType coordinates);
}

#endif
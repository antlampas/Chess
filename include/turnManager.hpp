/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TURNMANAGER_HPP
#define TURNMANAGER_HPP

#ifndef BOARD_HPP
#include "board.hpp"
#endif

class turnManager
{
    private:
    board* b;
    static turnManager* instance;
    char team;
    turnManager();
    turnManager(boardMapType);
    void setTurn(char team);
    void toggleTurn();
    public:
    turnManager(turnManager&&)            = delete;
    turnManager& operator=(turnManager&&) = delete;
    static turnManager& getInstance(boardMapType);
    static turnManager& getInstance();
    bool move(coordinatesType,coordinatesType);
    char getTurn();
};

#endif
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
#ifndef TIMER_HPP
#include "timer.hpp"
#endif

#ifdef TESTTURNMANAGER
#define private public
#endif

class turnManager
{
    private:
    board b                                      {};
    char team                                    {};
    timer t                                      {};
    std::chrono::duration<long int> turnDuration {};
    bool endTurnSignal                           {false};
    std::promise<void> exitSignal                {};
    std::thread checkTimer                       {};

    private:
    void setTurn(char team);
    void toggleTurn();

    public:
    turnManager();
    turnManager(boardMapType);
    ~turnManager();
    bool move(coordinatesType,coordinatesType);
    char getTurn();
    void endTurn();
    boardMapType getBoardStatus();
};

#endif
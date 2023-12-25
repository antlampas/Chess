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

class turnTimer : public timer
{};

class turnManager
{
    private:
    static turnManager* instance;
    board b                                      {};
    char team                                    {};
    turnTimer t                                  {};
    std::chrono::duration<long int> turnDuration {};
    std::promise<void> exitSignal                {};
    std::thread checkTimer                       {};

    private:
    turnManager();
    turnManager(boardMapType);
    void setTurn(char team);
    void toggleTurn();

    public:
    ~turnManager();
    static turnManager& getInstance(boardMapType);
    static turnManager& getInstance();
    bool move(coordinatesType,coordinatesType);
    char getTurn();
    boardMapType getBoardStatus();
};

#endif
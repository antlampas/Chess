/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <utility>
#include <iostream>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

turnManager::turnManager(boardMapType boardMap)
{
    board b(boardMap);
    this->b = std::move(b);
    this->setTurn('w');
    
    std::function<void()> checkTimer {[this](std::future<void> exitSignal,timer t)
                                        {
                                            std::promise<void> internalExitSignal {};
                                            while(exitSignal.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
                                            {
                                                std::this_thread::sleep_for(std::chrono::milliseconds(998));
                                                if(!this->t.checkCallback())
                                                    this->t.startTimer(turnManager:toggleTurn,this,std::move(internalExitSignal.get_future()));
                                                std::cout << this->getTurn() << std::endl;
                                            }
                                            if(!this->t.checkCallback())
                                                internalExitSignal.set_value();
                                        }};

    this->checkTimer(checkTimer,std::move(this->exitSignal.get_future()));
}

turnManager::turnManager()
{
    board b;
    this->b = std::move(b);
    this->setTurn('w');
    
    std::function<void()> checkTimer {[this](std::future<void> exitSignal,timer t)
                                        {
                                            std::promise<void> internalExitSignal {};
                                            while(exitSignal.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
                                            {
                                                std::this_thread::sleep_for(std::chrono::milliseconds(998));
                                                if(!this->t.checkCallback())
                                                    this->t.startTimer(turnManager:toggleTurn,this,std::move(internalExitSignal.get_future()));
                                                std::cout << this->getTurn() << std::endl;
                                            }
                                            if(!this->t.checkCallback())
                                                internalExitSignal.set_value();
                                        }};

    this->checkTimer(checkTimer,std::move(this->exitSignal.get_future()));
}

turnManager::~turnManager()
{
    this->exitSignal.set_value();
    this->checkTimer.join();
}
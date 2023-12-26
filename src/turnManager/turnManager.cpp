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

turnManager::turnManager() : turnManager(boardMapType()){}

turnManager::turnManager(boardMapType boardMap)
{
    if(!boardMap.empty())
    {
        board b(boardMap);
        this->b = std::move(b);
    }
    else
    {
        board b;
        this->b = std::move(b);
    }

    this->setTurn('w');
    
    this->t.setInterval(std::chrono::seconds(2));

    std::function<void(std::future<void>)> checkTimer = [this](std::future<void> exitSignal)
                                        {
                                            std::cout << "Starting Check timer" << std::endl;
                                            std::promise<void> internalExitSignal {};
                                            while(exitSignal.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
                                            {
                                                std::cout << "No exit request" << std::endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(998));
                                                if(!this->t.callbackStillRunning())
                                                {
                                                    std::cout << "Callback not running" << std::endl;
                                                    if(this->t.startTimer(&turnManager::toggleTurn,std::move(this),std::move(internalExitSignal.get_future())))
                                                        std::cout << "Timer Started" << std::endl;
                                                }
                                                std::cout << this->getTurn() << std::endl;
                                            }
                                            std::cout << "Exit request" << std::endl;
                                            if(!this->t.callbackStillRunning())
                                                internalExitSignal.set_value();
                                        };

    this->checkTimer = std::move(std::thread(checkTimer,std::move(this->exitSignal.get_future())));
}

turnManager::~turnManager()
{
    this->exitSignal.set_value();
    if(this->checkTimer.joinable())
        this->checkTimer.join();
}
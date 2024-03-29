/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <utility>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

turnManager::turnManager() : turnManager(boardMapType()){}

turnManager::turnManager(boardMapType boardMap)
{
    if(!boardMap.empty())
    {
        board b(boardMap);
        std::swap(b,this->b);
    }
    else
    {
        board b;
        std::swap(b,this->b);
    }

    this->setTurn('w');
    
    this->t.setInterval(std::chrono::seconds(10));

    std::function<void(std::future<void>)> checkTimer = [this](std::future<void> exitSignal)
                                        {
                                            std::promise<void> internalExitSignal {};
                                            do
                                            {
                                                std::this_thread::sleep_for(std::chrono::milliseconds(996));
                                                if(this->endTurnSignal)
                                                {
                                                    internalExitSignal.set_value();
                                                    this->endTurnSignal = false;
                                                }
                                                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                                                if(this->t.isCallbackEnded())
                                                {
                                                    internalExitSignal = std::promise<void> {};
                                                    this->t.startTimer(&turnManager::toggleTurn,std::move(this),std::move(internalExitSignal.get_future()));
                                                }
                                            }while(exitSignal.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout);

                                            if(!this->t.isCallbackStillRunning())
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
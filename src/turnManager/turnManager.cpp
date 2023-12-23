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
    std::function<void()> checkTimer {[this](std::future<void> exitSignal,timer t)
                                        {
                                            while(exitSignal.get_value() == std::future_status::timeout)
                                            {
                                                std::this_thread::wait_for(std::chrono::milliseconds(998));
                                                if(this->t.get_id() == std::thread::id{})
                                                    this->t.startTimer(&this->toggleTurn,std::move(exitSignal.get_future()));
                                                std::cout << this->getTurn() << std::endl;
                                            }
                                            if(this->t.get_id() != std::thread::id{})
                                                exitSignal.set_value();
                                        }};

    this->checkTimer(checkTimer,std::move(exitSignal.get_future()));
}

turnManager::turnManager()
{
    board b;
    this->b = std::move(b);
    this->setTurn('w');
    std::function<void()> checkTimer {[this](std::future<void> exitSignal,timer t)
                                        {
                                            while(exitSignal.get_value() == std::future_status::timeout)
                                            {
                                                std::this_thread::wait_for(std::chrono::milliseconds(998));
                                                if(this->t.get_id() == std::thread::id{})
                                                    this->t.startTimer(&this->toggleTurn,std::move(exitSignal.get_future()));
                                                std::cout << this->getTurn() << std::endl;
                                            }
                                            if(this->t.get_id() != std::thread::id{})
                                                exitSignal.set_value();
                                        }};

    this->checkTimer(checkTimer,std::move(exitSignal.get_future()));
}

turnManager::~turnManager()
{
    this->exitSignal.set_value();
    this->checkTimer.join();
    this->t.join();
}
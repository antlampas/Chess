/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#include "timer.hpp"
#endif

bool timer::startTimer(std::function<void()> f)
{
    std::future<void> requestExit = this->exitSignal.get_future();

    std::function<void()> function = [this](std::function<void> *func,std::future<void> reqExit)
                                    {
                                        this->startTime = std::chrono::steady_clock::now();
                                        this->stopTime  = this->startTime + this->interval;
                                        std::chrono::duration<long int> elapsedTime {std::chrono::steady_clock::now() - this->startTime};
                                        while(elapsedTime < this->interval)
                                        {
                                            if(reqExit.wait_for(std::chrono::seconds(1))==std::future_status::ready)
                                            {
                                                (*func)();
                                                break;
                                            }
                                            elapsedTime = std::chrono::steady_clock::now() - this->startTime;
                                        }
                                    };
    std::thread func {function,std::move(requestExit)};

    if((func.get_id() != std::thread::id{}) && (this->callback = std::move(func)))
        return true;
    else
        return false;
}

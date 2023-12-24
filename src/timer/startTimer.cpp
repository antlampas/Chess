/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#include "timer.hpp"
#endif

template<typename T,typename U> bool timer::startTimer(T f,U* obj,std::future<void> exitSignal)
{
    std::function<void(std::function<void()>*,std::future<void>)> function = std::move([this](std::function<void()>* func,std::future<void> reqExit)
                                    {
                                        this->startTime = std::chrono::steady_clock::now();
                                        this->stopTime  = this->startTime + this->interval;
                                        std::chrono::duration<long int> elapsedTime {std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime)};
                                        while(elapsedTime < this->interval)
                                        {
                                            std::this_thread::sleep_for(std::chrono::milliseconds(998))
                                            if(reqExit.wait_for(std::chrono::milliseconds(1))==std::future_status::ready)
                                                break;
                                            elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime);
                                        }
                                        f();
                                    });
    //std::thread func = std::thread(function,&f,dynamic_cast<obj_t> obj,std::move(exitSignal));

    if(func.get_id() != std::thread::id{})
        this->callback = std::move(std::thread(function,&f,obj,std::move(exitSignal)));

    if(this->callback.get_id() != std::thread::id{})
        return true;
    else
        return false;
}

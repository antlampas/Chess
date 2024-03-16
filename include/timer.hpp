/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <functional>
#include <thread>
#include <future>
#include <string>

#ifdef TESTTIMER
#define private public
#endif

class timer
{
    /* Properties about timer itself */
    private:
    std::chrono::time_point<std::chrono::steady_clock> startTime  {};
    std::chrono::time_point<std::chrono::steady_clock> stopTime   {};
    std::chrono::duration<long int>                    interval   {};
    std::string                                        name       {};

    /* Callback function properties */
    private:
    std::thread                                        callback   {};
    std::promise<void>                                 exitSignal {};

    /* Timer construction and destruction */
    public:
    timer();
    timer(long int);
    ~timer();

    /* Timer handling */
    void                                 setInterval(std::chrono::duration<long int>);
    bool                                 stopTimer();
    bool                                 isStarted();
    void                                 setName(std::string);
    std::chrono::duration<long int>      getElapsedTime();
    std::chrono::duration<long int>      getRemainingTime();
    std::string                          getName();
    template<typename T,typename U> bool startTimer(T f,U obj,std::future<void> exitSignal)
    {
        std::function<void(std::future<void>)> function = std::move([&,this,f,obj](std::future<void> reqExit)
        {
            this->startTime     = std::chrono::steady_clock::now();
            this->stopTime      = this->startTime + this->interval;
            std::chrono::duration<long int> elapsedTime {std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime)};
            while(elapsedTime < this->interval)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(998));
                if(reqExit.wait_for(std::chrono::milliseconds(1))==std::future_status::ready)
                    break;
                elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime);
            }
            (obj->*f)();
        });

        this->callback = std::move(std::thread(function,std::move(exitSignal)));

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        if(this->callback.joinable())
            return true;
        else
            return false;
    }
    
    /* Callback check */
    public:
    bool isCallbackStillRunning();
    bool isCallbackEnded();
};

#endif
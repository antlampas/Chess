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
#include <iostream>

#ifdef TESTTIMER
#define private public
#endif

class timer
{
    private:
    std::chrono::time_point<std::chrono::steady_clock> startTime {};
    std::chrono::time_point<std::chrono::steady_clock> stopTime  {};
    std::chrono::duration<long int> interval                     {};
    std::thread callback                                         {};
    bool callbackEnded                                       = true;
    std::promise<void> exitSignal;

    public:
    timer();
    timer(long int);
    ~timer();
    void setInterval(std::chrono::duration<long int>);
    template<typename T,typename U> bool startTimer(T f,U obj,std::future<void> exitSignal)
    {
        std::cout << "Start timer" << std::endl;
        std::function<void(std::future<void>)> function = std::move([this,f,obj](std::future<void> reqExit)
        {
            std::cout << "Start callback" << std::endl;
            this->callbackEnded = false;
            this->startTime = std::chrono::steady_clock::now();
            this->stopTime  = this->startTime + this->interval;
            std::chrono::duration<long int> elapsedTime {std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime)};
            while(elapsedTime < this->interval)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(998));
                std::cout << "Wait" << std::endl;
                if(reqExit.wait_for(std::chrono::milliseconds(1))==std::future_status::ready)
                {
                    std::cout << "Stop wait" << std::endl;
                    break;
                }
                elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime);
            }
            std::cout << "Execute" << std::endl;
            std::thread execute(f,obj);
            execute.join();
            this->callbackEnded = true;
        });

        this->callback = std::move(std::thread(function,std::move(exitSignal)));

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        if(this->callback.joinable())
            return true;
        else
            return false;
    }
    bool stopTimer();
    bool isStarted();
    bool callbackStillRunning();
    bool callbackEnded();
    std::chrono::duration<long int> getElapsedTime();
    std::chrono::duration<long int> getRemainingTime();
};

#endif
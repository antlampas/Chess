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
    std::promise<void> exitSignal;

    public:
    timer();
    timer(long int);
    ~timer();
    void setInterval(std::chrono::duration<long int>);
    template<typename T,typename U> bool startTimer(T,U*,std::future<void>);
    bool stopTimer();
    bool isStarted();
    bool checkCallback();
    std::chrono::duration<long int> getElapsedTime();
    std::chrono::duration<long int> getRemainingTime();
};

#endif
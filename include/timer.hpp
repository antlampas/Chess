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
    void setInterval(std::chrono::duration<long int>);
    bool startTimer(std::function<void()>,void*,std::future<void>);
    bool stopTimer();
    bool isStarted();
    bool checkCallback(); //TODO: implement
    std::chrono::duration<long int> getElapsedTime();
    std::chrono::duration<long int> getRemainingTime();
};

#endif
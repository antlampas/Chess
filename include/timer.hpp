#ifndef TURNMANAGER_HPP
#define TURNMANAGER_HPP

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
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::seconds> startTime {};
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::seconds> stopTime  {};
    std::chrono::duration<long int> interval                                          {};
    std::thread callback                                                              {};
    std::promise<void> exitSignal                                                     {};

    public:
    timer();
    timer(int,std::function<void(void*)>);
    void setInterval(std::chrono::duration<long int>);
    bool startTimer(std::function<void(void*)>);
    bool stopTimer();
    bool isStarted();
    std::chrono::duration<long int> getElapsedTime();
    std::chrono::duration<long int> getRemainingTime();
};

#endif
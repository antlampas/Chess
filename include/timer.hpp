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
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::seconds> stopTime {};
    std::chrono::duration<long int> interval {};
    std::thread callback {};
    std::promise<void> exitSignal;

    public:
    timer();
    timer(int,std::function<void(void*)>,void* args);
    void setInterval(std::chrono::duration<long int>);
    void setCallback(std::function<void(void*)>,void* args);
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration<long int> getElapsedTime();
    std::chrono::duration<long int> getRemainingTime();
};

#endif
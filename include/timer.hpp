#ifndef TURNMANAGER_HPP
#define TURNMANAGER_HPP

#include <chrono>
#include <functional>

#ifdef TESTING
#define private public
#endif

class timer
{
    private:
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::seconds> startTime;
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::seconds> stopTime;
    std::chrono::duration<long int,std::chrono::seconds> interval;
    std::function<void(void*)> callback;

    public:
    timer(int,std::function<void(void*)>);
    timer();
    void setInterval(std::chrono::duration<long int,std::chrono::seconds>);
    void setCallback(std::function<void(void*)>);
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration<long int,std::chrono::seconds> getElapsedTime();
    std::chrono::duration<long int,std::chrono::seconds> getRemainingTime();
};

#endif
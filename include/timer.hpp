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
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> stopTime;
    std::chrono::duration<short int> interval;
    std::function<void(void*)> callback;

    public:
    timer(int,std::function<void(void*)>);
    timer();
    void setInterval(std::chrono::duration<std::chrono::seconds>);
    void setCallback(std::function<void(void*)>);
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration<std::chrono::seconds> getElapsedTime();
    std::chrono::duration<std::chrono::seconds> getRemainingTime();
};

#endif
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
    std::chrono::time_point startTime;
    std::chrono::time_point stopTime;
    std::chrono::duration<short int> interval;
    std::function<void()> callback;

    public:
    timer(int,std::function<void()>);
    timer();
    void setInterval(std::chrono::duration);
    void setCallback(std::function<void(void*)>);
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration getElapsedTime();
    std::chrono::duration getRemainingTime();
};

#endif
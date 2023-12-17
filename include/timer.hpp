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
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::duration<short int,std::chrono::steady_clock>> startTime;
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::duration<short int,std::chrono::steady_clock>> stopTime;
    std::chrono::duration<short int,std::chrono::steady_clock> interval {1};
    std::function<void(void*)> callback;

    public:
    timer(int,std::function<void(void*)>);
    timer();
    void setInterval(std::chrono::duration<short int,std::chrono::steady_clock>);
    void setCallback(std::function<void(void*)>);
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration<short int,std::chrono::steady_clock> getElapsedTime();
    std::chrono::duration<short int,std::chrono::steady_clock> getRemainingTime();
};

#endif
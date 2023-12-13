#ifndef TURNMANAGER_HPP
#define TURNMANAGER_HPP

#include <chrono>

#ifdef TESTING
    #define private public
#endif

class timer
{
    private:
    static timer* instance;
    std::chrono::duration<short int> interval;
    std::chrono::duration<short int> elapsedTime;
    timer(int);
    timer();
    timer(timer&);
    timer(timer&&);

    public:
    static timer& getInstance();
    void setInterval();
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration getElapsedTime();
};

#endif
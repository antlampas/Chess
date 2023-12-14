#ifndef TURNMANAGER_HPP
#define TURNMANAGER_HPP

#include <chrono>

#ifdef TESTING
    #define private public
#endif

class timer
{
    private:
    std::chrono::duration<short int> interval;
    std::chrono::duration<short int> elapsedTime;
    void (*callback)(void*);

    public:
    timer(int);
    timer();
    void setInterval();
    void setCallback(void (*f)(void*),void*);
    bool startTimer();
    bool stopTimer();
    bool isStarted();
    std::chrono::duration getElapsedTime();
};

#endif
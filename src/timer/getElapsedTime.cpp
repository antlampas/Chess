/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_CPP
#include "timer.cpp"
#endif

std::chrono::duration<long int,std::chrono::seconds> timer::getElapsedTime()
{
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::seconds> now = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::steady_clock::now());
    std::chrono::duration<long int,std::chrono::seconds> d = now - this->startTime;
    return d;
}
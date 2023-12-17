/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_CPP
#include "timer.cpp"
#endif

std::chrono::duration<std::chrono::seconds> timer::getElapsedTime()
{
    return std::chrono::duration<std::chrono::seconds>(std::chrono::steady_clock::now() - this->startTime);
}
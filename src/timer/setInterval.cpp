/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_CPP
#include "timer.cpp"
#endif

void timer::setInterval(std::chrono::duration interval)
{
    this->interval = interval;
}

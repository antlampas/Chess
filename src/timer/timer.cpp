/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#include "timer.hpp"
#endif

timer::timer(){}
timer::timer(long int interval) : interval(interval){}
timer::~timer()
{
    this->exitSignal.set_value();
    if(this->callback.joinable());
        this->callback.join();
}
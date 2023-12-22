/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#include "timer.hpp"
#endif

bool timer::startTimer(std::function<void(void*)> f)
{
    std::future<void> requestExit = this->exitSignal.get_future();
    if((std::thread func {f,requestExit}) && (this->callback = std::move(func)))
        return true;
    else
        return false;
}

/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#include "timer.hpp"
#endif

bool timer::isCallbackEnded()
{
    if(this->callback.joinable() && this->callbackEnded)
    {
        this->callback.join();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        return true;
    }else if(!this->callback.joinable())
        return true;
    else
        return false;
}
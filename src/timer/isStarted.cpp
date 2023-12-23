/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_HPP
#include "timer.hpp"
#endif

bool timer::isStarted()
{
    if(this->callback.get_id()!= std::thread::id{})
        return true;
    else
        return false;
}

/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TIMER_CPP
#include "timer.hpp"
#endif

timer::timer() : interval(1),callback(nullptr),startTime(std::chrono::steady_clock::now()),stopTime(std::chrono::steady_clock::now()){}
timer::timer(int interval,std::function<void(void*)> callback) : interval(interval),callback(callback),startTime(std::chrono::steady_clock::now()),stopTime(std::chrono::steady_clock::now()){}

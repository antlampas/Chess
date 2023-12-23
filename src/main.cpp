/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif
#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif
#ifndef TIMER_HPP
#include "timer.hpp"
#endif

int main(int argc,char** argv)
{ 
    turnManager& tm = turnManager::getInstance();
    timer tt;
    
    return 0;
}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <algorithm>
#include <csignal>
#include <exception>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

bool stop = false;

void setStop(int signal)
{
    stop = true;
}

int main(int argc,char** argv)
{ 
    turnManager* tm = new turnManager;

    std::signal(SIGINT,setStop);

    for(int i=0;i<10;i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        tm->endTurn();
    }

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        if(stop) break;
    }

    return 0;
}
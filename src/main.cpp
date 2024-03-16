/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <exception>
#include <utility>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

int main(int argc,char** argv)
{
    board b;
    for(auto a: b.publicBoardMap)
    {
        for(auto b: a)
            std::cout << b << " ";
        std::cout << std::endl;
    }
    board c;
    
    for(auto a: c.publicBoardMap)
    {
        for(auto b: a)
            std::cout << b << " ";
        std::cout << std::endl;
    }

    for(auto a: b.publicBoardMap)
    {
        for(auto b: a)
            std::cout << b << " ";
        std::cout << std::endl;
    }

    return 1;
}
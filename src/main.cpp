/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <exception>
#include <utility>
#include <random>
#include <algorithm>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

int main(int argc,char** argv)
{
    auto r = std::default_random_engine {};

    board a {};

    std::vector<std::string> vec {};
    boardMapType bm {a.boardStatus()};
    for(auto row: bm)
        for(auto column: row)
            vec.push_back(column);
    std::shuffle(vec.begin(),vec.end(),r);
    int i = 0;
    for(int row: {0,1,2,3,4,5,6,7})
        for(int column: {0,1,2,3,4,5,6,7})
        {
            bm.at(row).at(column) = vec.at(i);
            i++;
        }
    
    board b {bm};
    board c {std::move(a)};

    for(auto row: a.publicBoardMap)
    {
        for(auto col: row)
            std::cout << col << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(auto row: b.publicBoardMap)
    {
        for(auto col: row)
            std::cout << col << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(auto row: c.publicBoardMap)
    {
        for(auto col: row)
            std::cout << col << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(auto row: a.publicBoardMap)
    {
        for(auto col: row)
            std::cout << col << " ";
        std::cout << std::endl;
    }

    return 1;
}
/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
 
#include <iostream>
#include <algorithm>
#include <random>

#ifndef BOARD_HPP
#include "board.hpp"
#endif
#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

int main(int argc,char** argv)
{
    std::random_device r;
    std::mt19937 g(r());

    std::vector<std::string> pieces      {"wp","wp","wp","wp","wp","wp","wp","wp","wr","wr","wn","wn","wb","wb","wk","wq","bp","bp","bp","bp","bp","bp","bp","bp","br","br","bn","bn","bb","bb","bk","bq"};
    
    std::shuffle(pieces.begin(),pieces.end(),g);

    
    boardMapType randomBoard = boardMapType(8,columnType(8,squareType("e")));

    for(auto p: pieces)
        randomBoard.at(r()%8).at(r()%8) = p;
    
    turnManager& tm = turnManager::getInstance(randomBoard);
    std::for_each(board.begin(),board.end(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){std::cout << column << " ";});std::cout << std::endl;});
    std::cout << std::endl << std::endl;
    delete tm;

    turnManager& tm = turnManager::getInstance(randomBoard);
    std::for_each(board.begin(),board.end(),[](std::vector<std::string> row){std::for_each(row.begin(),row.end(),[](std::string column){std::cout << column << " ";});std::cout << std::endl;});
    std::cout << std::endl << std::endl;
    delete tm;

    return 0;
}
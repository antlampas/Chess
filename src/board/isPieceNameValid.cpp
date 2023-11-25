#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isPieceNameValid(std::string name)
{
    std::regex nameFormat("^[wb][prnbkq]$|^e$");
    
    return std::regex_match(name,nameFormat);
}
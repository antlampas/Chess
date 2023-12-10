/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <regex>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

bool board::isPieceNameValid(std::string name)
{
    std::regex nameFormat("^[wb][prnbkq]$|^e$");
    
    return std::regex_match(name,nameFormat);
}
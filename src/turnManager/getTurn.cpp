/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <regex>
#include <exception>

#ifndef TURNMANAGER_HPP
#include "turnManager.hpp"
#endif

char getTurn()
{
    std::regex teamFormat = "[wb]";

    if(std::regex_match(team,teamFormat))
        return this->team;
    else
        throw std::Exception("Invalid team")
}
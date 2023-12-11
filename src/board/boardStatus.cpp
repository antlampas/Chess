/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <algorithm>

#ifndef BOARD_HPP
#include "board.hpp"
#endif

boardMapType board::boardStatus()
{
    return this->boardMap;
}
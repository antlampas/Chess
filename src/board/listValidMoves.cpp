/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#include "board.hpp"
#endif

std::vector<std::string> board::listValidMoves(std::string coordinates)
{
    std::pair<int,int> decodedCoordinates = this->decodeCoordinates(coordinates);

    const int& row    {decodedCoordinates.first};
    const int& column {decodedCoordinates.second};
    
    const std::string& piece = this->getPieceInSquare(coordinates);
    std::vector<std::string> movesList;

    if(this->isPieceNameValid(piece))
    {
        if(piece.at(1)=='p')
        {
            if(piece.at(0) == 'w')
            {
                if((((row+1)<9)&&((column-1)>-1)))
                {
                    std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column-1));
                    if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                        movesList.push_back(square);
                }
                if((((row+1)<9)&&((column+1)<9)))
                {
                    std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column+1));
                    if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                        movesList.push_back(square);
                }
                if((((row+1)<9)))
                {
                    std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column));
                    if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                        movesList.push_back(square);
                }
            }
            else if(piece.at(0) == 'b')
            {
                if((((row-1)>-1)&&((column-1)>-1)))
                {
                    std::string square = this->encodeCoordinates(std::pair<int,int>(row-1,column-1));
                    if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                        movesList.push_back(square);
                }
                if((((row-1)>-1)&&((column+1)<9)))
                {
                    std::string square = this->encodeCoordinates(std::pair<int,int>(row-1,column+1));
                    if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                        movesList.push_back(square);
                }
                if((((row-1)>-1)))
                {
                    std::string square = this->encodeCoordinates(std::pair<int,int>(row-1,column));
                    if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                        movesList.push_back(square);
                }
            }
        }
        else if(piece.at(1)=='r'){}
        else if(piece.at(1)=='n'){}
        else if(piece.at(1)=='b'){}
        else if(piece.at(1)=='q'){}
        else if(piece.at(1)=='k'){}
        return movesList;
    }
    else
        return std::vector<std::string>();
}
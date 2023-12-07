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

    if(decodedCoordinates.first != -1)
    {
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
                    if((((row+1)<8)&&((column-1)>-1)))
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column-1));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                    if((((row+1)<8)&&((column+1)<8)))
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column+1));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                    if((((row+1)<8)))
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
                    if((((row-1)>-1)&&((column+1)<8)))
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
            else if(piece.at(1)=='r')
            {
                if((row!=0) && (row!=7))
                    if(!this->isColumnClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(7,column))) && !this->isColumnClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(0,column))))
                    {
                        for(int i=row+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                        for(int i=row-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                    }
                else if((row==0))
                    if(!this->isColumnClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(7,column))))
                        for(int i=row+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                else if((row==7))
                    if(!this->isColumnClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(0,column))))
                        for(int i=row-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                if((column!=0) && (column!=7))
                    if(!this->isRowClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(row,7))) && !this->isRowClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(row,0))))
                    {
                        for(int i=column+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                        for(int i=column-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                    }
                else if((column==0))
                    if(!this->isColumnClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(7,column))))
                        for(int i=column+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                else if((column==7))
                    if(!this->isColumnClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(0,column))))
                        for(int i=column-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
            }
            else if(piece.at(1)=='n')
            {
                if(((column - 2) > -1) && ((row + 1) <  8)) 
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+1,column-2)));
                if(((column - 1) > -1) && ((row + 2) <  8))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+2,column-1)));
                if(((column - 2) > -1) && ((row - 1) > -1))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-1,column-2)));
                if(((column - 1) > -1) && ((row - 2) > -1))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-2,column-1)));
                if(((column + 2) <  8) && ((row + 1) <  8))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+1,column+2)));
                if(((column + 1) <  8) && ((row + 2) <  8))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+2,column+1)));
                if(((column + 2) <  8) && ((row - 1) > -1))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-1,column+2)));
                if(((column + 1) <  8) && ((row - 2) > -1))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-2,column+1)));
            }
            else if(piece.at(1)=='b')
            {
                if((row == 0) && (column == 0))
                    for(int i=1;(!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,i))) && (i<8));i++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,i)));
                else if((row == 7) && (column == 0))
                    for(int i=6,j=1;!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))) && (i > -1 && j < 8);i--,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,i)));
                else if((row == 7) && (column == 7))
                    for(int i=6;(!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,i))) && (i>-1));i--)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,i)));
                else if((row == 0) && (column == 7))
                    for(int i=1,j=6;!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))) && (i < 8 && j > -1);i++,j--)
                            movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,i)));
                else
                {
                    for(int i=row+1,j=column+1;!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))) && (i < 8) && (j < 8);i++,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row+1,j=column-1;!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))) && (i < 8) && (j > -1);i++,j--)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row-1,j=column-1;!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))) && (i > -1) && (j > -1);i++,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row-1,j=column+1;!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))) && (i > -1) && (j < 8);i++,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                }
            }
            else if(piece.at(1)=='k')
            {
                if(((row + 1) < 8) && ((column - 1) > -1) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row+1,column-1))).at(0) != piece.at(0)))
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+1,column-1)));
                if(((row + 1) < 8) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row+1,column))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+1,column)));
                if(((row + 1) < 8) && ((column + 1) < 8) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row+1,column+1))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row+1,column+1)));
                if(((column + 1) < 8) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row,column+1))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,column+1)));
                if(((row - 1) > -1) && ((column + 1) < 8) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row-1,column+1))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-1,column+1)));
                if(((row - 1) > 8) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row-1,column))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-1,column)));
                if(((row - 1) > -1) && ((column - 1) > -1) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row-1,column-1))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row-1,column-1)));
                if(((column - 1) > -1) && (this->getPieceInSquare(this->encodeCoordinates(std::pair<int,int>(row,column-1))).at(0) != piece.at(0)))
                    movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,column-1)));
            }
            else if(piece.at(1)=='q')
            {
                return std::vector<std::string>();
            }
            return movesList;
        }
        else
            return std::vector<std::string>();
    }
    else
        return std::vector<std::string>();
}
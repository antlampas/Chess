/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <iostream>

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

        std::string previousColumn = this->encodeCoordinates(std::pair<int,int>(row,column-1));
        std::string nextColumn     = this->encodeCoordinates(std::pair<int,int>(row,column+1));
        std::string previousRow    = this->encodeCoordinates(std::pair<int,int>(row-1,column));
        std::string nextRow        = this->encodeCoordinates(std::pair<int,int>(row+1,column));
        
        const bool isUpperColumnClogged = this->isColumnClogged(nextRow,this->encodeCoordinates(std::pair<int,int>(7,column)));
        const bool isLowerColumnClogged = this->isColumnClogged(this->encodeCoordinates(std::pair<int,int>(0,column)),previousRow);
        const bool isRightSideClogged   = this->isRowClogged(nextColumn,this->encodeCoordinates(std::pair<int,int>(row,7)));
        const bool isLeftSideClogged    = this->isRowClogged(this->encodeCoordinates(std::pair<int,int>(row,0)),previousColumn);

        const bool isTopLeftInsideBounds     = ( (row + 1) < 8) && ( (column - 1) > -1);
        const bool isTopRightInsideBounds    = ( (row + 1) < 8) && ( (column + 1) <  8);
        const bool isBottomLeftInsideBounds  = ( (row - 1) > -1) && ( (column - 1) > -1);
        const bool isBottomRightInsideBounds = ( (row - 1) > -1) && ( (column + 1) < 8);
        const bool isTopInsideBounds         = ( (row + 1) < 8);
        const bool isBottomInsideBounds      = ( (row - 1) > -1);
        const bool isOnBottom                = ( row == 0 );
        const bool isOnTop                   = ( row == 7) ;
        const bool isOnLeft                  = ( column == 0 );
        const bool isOnRight                 = ( column == 7 );
        const bool isNotOnBottomOrTop        = ( (row != 0) && (row != 7));
        const bool isNotOnLeftOrRight        = ( (column != 0) && (column != 7));

        if(this->isPieceNameValid(piece))
        {
            if(piece.at(1)=='p')
            {
                if(piece.at(0) == 'w')
                {
                    if(isTopLeftInsideBounds)
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column-1));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                    if(isTopRightInsideBounds)
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column+1));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                    if(isTopInsideBounds)
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row+1,column));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                }
                else if(piece.at(0) == 'b')
                {
                    if(isBottomLeftInsideBounds)
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row-1,column-1));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                    if(isBottomRightInsideBounds)
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row-1,column+1));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                    if(isBottomInsideBounds)
                    {
                        std::string square = this->encodeCoordinates(std::pair<int,int>(row-1,column));
                        if((this->getPieceInSquare(square) == "e") || (this->getPieceInSquare(square).at(0) != piece.at(0)))
                            movesList.push_back(square);
                    }
                }
            }
            else if(piece.at(1)=='r')
            {
                //Column check
                if(isNotOnBottomOrTop)
                {
                    int endRow = upperColumnFreeSquare(row,column,nextRow,piece);
                    for(int i=row+1;i<=endRow;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                    endRow = lowerColumnFreeSquare(row,column,previousRow,piece);
                    for(int i=row-1;i>=endRow;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                }
                if(isOnBottom)
                {
                    int endRow = upperColumnFreeSquare(row,column,nextRow,piece);
                    for(int i=row+1;i<=endRow;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                }
                if(isOnTop)
                {
                    int endRow = lowerColumnFreeSquare(row,column,previousRow,piece);
                    for(int i=row-1;i>=endRow;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                }
                //Row check
                if(isNotOnLeftOrRight)
                {
                    int endColumn = rightRowFreeSquare(row,column,nextColumn,piece);
                    for(int i=column+1;i<=endColumn;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                    endColumn = leftRowFreeSquare(row,column,previousColumn,piece);
                    for(int i=column-1;i>=endColumn;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                }
                if(isOnLeft)
                {
                    int endColumn = rightRowFreeSquare(row,column,nextColumn,piece);
                    for(int i=column+1;i<=endColumn;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                }
                if(isOnRight)
                {
                    int endColumn = leftRowFreeSquare(row,column,previousColumn,piece);
                    for(int i=column-1;i>=endColumn;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                }
            }
            else if(piece.at(1)=='n')
            {
                std::vector<std::string> moves ={ \
                                                    this->encodeCoordinates(std::pair<int,int>(row+1,column-2)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row+1,column+2)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row-1,column-2)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row-1,column+2)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row+2,column-1)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row+2,column+1)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row-2,column-1)), \
                                                    this->encodeCoordinates(std::pair<int,int>(row-2,column+1))  \
                                                };
                
                std::vector<std::string> validMoves;

                for(auto move: moves)
                    if(!move.empty())
                        validMoves.push_back(move);

                for(auto move: validMoves)
                    if(!this->isMoveClogged(coordinates,move))
                        movesList.push_back(move);
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
                    for(int i=row+1,j=column+1;((i < 8) && (j < 8) && !this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i++,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row+1,j=column-1;((i < 8) && (j > -1) &&!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i++,j--)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row-1,j=column-1;((i > -1) && (j > -1) && !this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i--,j--)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row-1,j=column+1;((i > -1) && (j < 8) && !this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i--,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                }
            }
            else if(piece.at(1)=='k')
            {
                std::vector<std::string> moves {
                                                this->encodeCoordinates(std::pair<int,int>(row+1,column-1)), \
                                                this->encodeCoordinates(std::pair<int,int>(row+1,column)), \
                                                this->encodeCoordinates(std::pair<int,int>(row+1,column+1)), \
                                                this->encodeCoordinates(std::pair<int,int>(row,column+1)), \
                                                this->encodeCoordinates(std::pair<int,int>(row-1,column+1)), \
                                                this->encodeCoordinates(std::pair<int,int>(row-1,column)), \
                                                this->encodeCoordinates(std::pair<int,int>(row-1,column-1)), \
                                                this->encodeCoordinates(std::pair<int,int>(row,column-1)) \
                                                };
                
                std::vector<std::string> validMoves;

                for(auto move: moves)
                    if(!move.empty())
                        validMoves.push_back(move);
                
                for(auto move: validMoves)
                    if(move.at(0) != piece.at(0)) movesList.push_back(move);
            }
            else if(piece.at(1)=='q')
            {
                //Check Column and Row
                if((row!=0) && (row!=7))
                {
                    if(!isUpperColumnClogged && !isLowerColumnClogged)
                    {
                        for(int i=row+1;i<8;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                        for(int i=row-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                    }
                }
                else if((row==0))
                {
                    if(!isUpperColumnClogged)
                    {
                        for(int i=row+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                    }
                }
                else if((row==7))
                {
                    if(!isLowerColumnClogged)
                    {
                        for(int i=row-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,column)));
                    }
                }

                if((column!=0) && (column!=7))
                {
                    if(!isLeftSideClogged && !isRightSideClogged)
                    {
                        for(int i=column+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                        for(int i=column-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                    }
                }
                else if((column==0))
                {
                    if(!isRightSideClogged)
                    {
                        for(int i=column+1;i<7;i++)  movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                    }
                }
                else if((column==7))
                {
                    if(!isLeftSideClogged)
                    {
                        for(int i=column-1;i>-1;i--) movesList.push_back(this->encodeCoordinates(std::pair<int,int>(row,i)));
                    }
                }
                //End check Column and Row

                //Check Diagonals
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
                    for(int i=row+1,j=column+1;((i < 8) && (j < 8) && !this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i++,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row+1,j=column-1;((i < 8) && (j > -1) &&!this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i++,j--)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row-1,j=column-1;((i > -1) && (j > -1) && !this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i--,j--)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                    for(int i=row-1,j=column+1;((i > -1) && (j < 8) && !this->isDiagonalClogged(coordinates,this->encodeCoordinates(std::pair<int,int>(i,j))));i--,j++)
                        movesList.push_back(this->encodeCoordinates(std::pair<int,int>(i,j)));
                }
                //End check Diagonals
            }
            else
                return std::vector<std::string>(std::string(''));
            return movesList;
        }
        else
            return std::vector<std::string>(std::string(''));
    }
    else
        return std::vector<std::string>(std::string(''));
}
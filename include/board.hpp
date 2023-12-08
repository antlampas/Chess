/*
 *
 * FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <utility>
#include <vector>
#include <array>
#include <string>

#ifdef DEBUG
    #define private public
#endif

using boardMapType = std::vector<std::vector<std::string>>;

class board{
    /*
    * e = empty square
    * q = queen
    * k = king
    * n = knight
    * r = rook
    * b = bishop
    * p = pawn
    *
    * b = black
    * w = white
    *
    * bp = black pawn
    * wp = white pawn
    * bq = black queen
    * wq = white queen
    * etc.
    *
    * Coordinates id: it's a string like this: "a1", "b1", "c6", etc...
    */
    private:
        boardMapType boardMap = boardMapType(8,std::vector<std::string>(8,std::string("e")));
        std::vector<std::string> tookPieces;
        std::string error;
    private:
        std::pair<int,int> decodeCoordinates(std::string);
        std::pair<char,char> decodePieceName(std::string);
        std::string encodeCoordinates(std::pair<int,int>);
        bool isColumnClogged(std::string,std::string);   //Starting position, end position
        bool isCoordinateValid(std::string);
        bool isDiagonalClogged(std::string,std::string); //Starting position, end position
        bool isFrontClogged(std::string);                //Starting position, end position
        bool isMoveClogged(std::string,std::string);     //Starting position, end position
        bool isMoveValid(std::string,std::string);       //Starting position, end position
        bool isRowClogged(std::string,std::string);      //Starting position, end position
        bool isPieceNameValid(std::string);
        std::string getPieceInSquare(std::string);
        int upperColumnFreeSquare(int,int,std::string,std::string);
        int lowerColumnFreeSquare(int,int,std::string,std::string);
        int rightRowFreeSquare(int,int,std::string,std::string);
        int leftRowFreeSquare(int,int,std::string,std::string);
    public:
        board();
        board(boardMapType);
        boardMapType boardStatus();
        std::vector<std::string> listValidMoves(std::string);
        bool move(std::string,std::string);
};

#endif
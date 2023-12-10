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
        inline std::pair<int,int> decodeCoordinates(std::string);
        inline std::pair<char,char> decodePieceName(std::string);
        inline std::string encodeCoordinates(std::pair<int,int>);
        inline std::string getPieceInSquare(std::string);
        inline bool isColumnClogged(std::string,std::string);   //Starting position, end position
        inline bool isCoordinateValid(std::string);
        inline bool isDiagonalClogged(std::string,std::string); //Starting position, end position
        inline bool isFrontClogged(std::string);                //Starting position, end position
        inline bool isMoveClogged(std::string,std::string);     //Starting position, end position
        inline bool isMoveValid(std::string,std::string);       //Starting position, end position
        inline bool isPieceNameValid(std::string);
        inline bool isRowClogged(std::string,std::string);      //Starting position, end position
        inline int leftRowFreeSquare(int,int,std::string,std::string);
        inline int lowerColumnFreeSquare(int,int,std::string,std::string);
        inline int rightRowFreeSquare(int,int,std::string,std::string);
        inline int upperColumnFreeSquare(int,int,std::string,std::string);
    public:
        board();
        board(boardMapType);
        boardMapType boardStatus();
        std::vector<std::string> listValidMoves(std::string);
        bool move(std::string,std::string);
};

#endif
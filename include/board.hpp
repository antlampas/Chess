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

#ifdef TESTBOARD
#define private public
#endif

using boardMapType           = std::vector<std::vector<std::string>>;
using rowType                = std::vector<std::vector<std::string>>;
using columnType             = std::vector<std::string>;
using squareType             = std::string;
using coordinatesType        = std::string;
using pieceType              = std::string;
using decodedCoordinatesType = std::pair<int,int>;
using decodedpieceType       = std::pair<char,char>;
using decodedRowType         = int;
using decodedColumnType      = int;

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
        boardMapType boardMap = rowType(8,columnType(8,squareType("e")));
        std::vector<pieceType> tookPieces;
        std::string error;
    private:
        decodedCoordinatesType decodeCoordinates(coordinatesType);
        decodedpieceType decodePieceName(pieceType);
        coordinatesType encodeCoordinates(decodedCoordinatesType);
        pieceType getPieceInSquare(pieceType);
        bool isColumnClogged(coordinatesType,coordinatesType);   //Starting position, end position
        bool isCoordinateValid(coordinatesType);
        bool isDiagonalClogged(coordinatesType,coordinatesType); //Starting position, end position
        bool isFrontClogged(coordinatesType,coordinatesType);    //Starting position, end position
        bool isMoveClogged(coordinatesType,coordinatesType);     //Starting position, end position
        bool isMoveValid(coordinatesType,coordinatesType);       //Starting position, end position
        bool isPieceNameValid(pieceType);
        bool isRowClogged(coordinatesType,coordinatesType);      //Starting position, end position
        int leftRowFreeSquare(decodedRowType,decodedColumnType,coordinatesType,pieceType);
        int lowerColumnFreeSquare(decodedRowType,decodedColumnType,coordinatesType,pieceType);
        int rightRowFreeSquare(decodedRowType,decodedColumnType,coordinatesType,pieceType);
        int upperColumnFreeSquare(decodedRowType,decodedColumnType,coordinatesType,pieceType);
    public:
        board();
        board(boardMapType);
        boardMapType boardStatus();
        std::vector<coordinatesType> listValidMoves(coordinatesType);
        bool move(coordinatesType,coordinatesType);
};

#endif
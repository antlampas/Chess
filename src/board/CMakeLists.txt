#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_library(board $<$<STREQUAL:$<UPPER_CASE:"${LIBRARIES_LINKING}">,"SHARED">:$<UPPER_CASE:${LIBRARIES_LINKING}>>$<$<STREQUAL:$<UPPER_CASE:"${LIBRARIES_LINKING}">,"STATIC">:$<UPPER_CASE:${LIBRARIES_LINKING}>>
            board.cpp
            boardStatus.cpp
            decodeCoordinates.cpp
            decodePieceName.cpp
            encodeCoordinates.cpp
            getPieceInSquare.cpp
            isColumnClogged.cpp
            isCoordinateValid.cpp
            isDiagonalClogged.cpp
            isFrontClogged.cpp
            isMoveClogged.cpp
            isMoveValid.cpp
            isPieceNameValid.cpp
            isRowClogged.cpp
            leftRowFreeSquare.cpp
            listValidMoves.cpp
            lowerColumnFreeSquare.cpp
            move.cpp
            rightRowFreeSquare.cpp
            upperColumnFreeSquare.cpp
           )


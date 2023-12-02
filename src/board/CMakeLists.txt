#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_library(board SHARED
            board.cpp
            boardStatus.cpp
            decodeCoordinates.cpp
            decodePieceName.cpp
            getPieceInSquare.cpp
            isColumnClogged.cpp
            isCoordinateValid.cpp
            isDiagonalClogged.cpp
            isFrontClogged.cpp
            isMoveClogged.cpp
            isMoveValid.cpp
            isPieceNameValid.cpp
            isRowClogged.cpp
            listValidMoves.cpp
            move.cpp
           )
cmake_minimum_required(VERSION 3.10)
project(Chess)
add_library(Board SHARED
            board/board.cpp
            board/boardStatus.cpp
            board/decodeCoordinates.cpp
            board/decodePieceName.cpp
            board/getPieceInSquare.cpp
            board/isColumnClogged.cpp
            board/isCoordinateValid.cpp
            board/isDiagonalClogged.cpp
            board/isFrontClogged.cpp
            board/isMoveClogged.cpp
            board/isMoveValid.cpp
            board/isPieceNameValid.cpp
            board/isRowClogged.cpp
            board/listValidMoves.cpp
            board/move.cpp)
add_executable(Chess main.cpp)
target_link_libraries(Chess Board)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
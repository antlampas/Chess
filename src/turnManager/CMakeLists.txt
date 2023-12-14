#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_library(turnManager $<$<STREQUAL:$<UPPER_CASE:"${LIBRARIES_LINKING}">,"SHARED">:$<UPPER_CASE:${LIBRARIES_LINKING}>>$<$<STREQUAL:$<UPPER_CASE:"${LIBRARIES_LINKING}">,"STATIC">:$<UPPER_CASE:${LIBRARIES_LINKING}>>
            getInstance.cpp
            getTurn.cpp
            move.cpp
            setTurn.cpp
            toggleTurn.cpp
            turnManager.cpp
           )
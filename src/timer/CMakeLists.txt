#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_library(timer $<$<STREQUAL:$<UPPER_CASE:"${LIBRARIES_LINKING}">,"SHARED">:SHARED>$<$<STREQUAL:$<UPPER_CASE:"${LIBRARIES_LINKING}">,"STATIC">:STATIC>
            getElapsedTime.cpp
            isStarted.cpp
            setCallback.cpp
            setInterval.cpp
            startTimer.cpp
            stopTimer.cpp
            timer.cpp
           )
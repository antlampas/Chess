#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

add_library(timer SHARED
            getElapsedTime.cpp
            getRemainingTime.cpp
            isCallbackEnded.cpp
            isCallbackStillRunning.cpp
            isStarted.cpp
            setInterval.cpp
            stopTimer.cpp
            timer.cpp
           )
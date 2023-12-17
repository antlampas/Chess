#!/bin/bash

if ! [[ -d build ]]
then
    mkdir build
fi
cd build
cmake .. -DCMAKE_BUILD_TYPE="$1" -DLIBRARIES_LINKING="$2" -DTESTING="${*:3}" && make
cd ..

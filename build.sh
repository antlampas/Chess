#!/bin/bash

if ! [[ -d build ]]
then
    mkdir build
fi
cd build
cmake -DCMAKE_BUILD_TYPE="$1" -DVERSION="${2}" .. && make
cd ..

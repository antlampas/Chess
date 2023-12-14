#!/bin/bash

# if [[ -d build ]]
# then
#     rm -rvf build/*
# else
#     mkdir build
# fi
cd build
cmake .. -DCMAKE_BUILD_TYPE="$1" -DLIBRARIES_LINKING="$2" -DTEST="$3" && make
cd ..
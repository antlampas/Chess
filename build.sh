#!/bin/bash

# if [[ -d build ]]
# then
#     rm -rvf build/*
# else
#     mkdir build
# fi
cd build
cmake .. -DCMAKE_BUILD_TYPE="$1" && make
cd ..
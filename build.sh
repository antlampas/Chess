#!/bin/bash

if [[ -d build ]]
then
    rm -rvf build/*
else
    mkdir build
fi
cd build
cmake ..
make
cd ..

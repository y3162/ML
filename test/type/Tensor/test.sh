#!/bin/bash

g++ -O0 -D DEBUG_TENSOR -c ../../../src/ML.cpp -o ML.o -std=c++14

for file in *.cpp
do
    name=${file%.cpp}
    g++ -g -c ${name}.cpp -o test.o -std=c++14
    g++ -g ML.o test.o -o test

    ./test 1> output.txt 2>&1
    diff ${name}.ans output.txt

    if [ $? -eq 0 ]; then
        echo ✅Tensor:${name}
    else
        echo ❌Tensor:${name}
    fi

    rm test.o test output.txt
    done

rm ML.o

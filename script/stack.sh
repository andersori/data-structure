#!/bin/bash

g++ -Wall -fexceptions -std=c++11 -g  -c ../test/stack.cpp -o ../obj/stack.o
g++  -o ../bin/stack ../obj/stack.o
./../bin/stack
#!/bin/bash

g++ -Wall -fexceptions -std=c++11 -g  -c ../test/doublylist.cpp -o ../obj/doublylist.o
g++  -o ../bin/doublylist ../obj/doublylist.o
./../bin/doublylist
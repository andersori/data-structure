#!/bin/bash

g++ -Wall -fexceptions -std=c++11 -g  -c ../test/queue.cpp -o ../obj/queue.o
g++  -o ../bin/queue ../obj/queue.o
./../bin/queue
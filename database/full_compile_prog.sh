#! /bin/bash
g++ -Wall -g -c data.cpp
g++ -Wall -g -c functions.cpp
g++ -Wall -g -c prog.cpp
g++ prog.o data.o functions.o -o prog
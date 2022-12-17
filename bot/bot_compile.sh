#! /bin/bash
g++ -Wall -g -c get_conf_file.cpp
g++ -Wall -g main.cpp  get_conf_file.o -o bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread
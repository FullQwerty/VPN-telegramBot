#! /bin/bash
g++ telegram_bot.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread
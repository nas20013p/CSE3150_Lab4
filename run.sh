#!/bin/bash

clear
g++ -std=c++11 Node.cpp LinkedList.cpp test_linked_list.cpp -I./include -o test
./test

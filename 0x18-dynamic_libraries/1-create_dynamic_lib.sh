#!/bin/bash
gcc -fPIC -g -c -Wall *.c
gcc -shared -o liball.so *.o

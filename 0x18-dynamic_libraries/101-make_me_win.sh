#!/bin/bash
gcc -shared -o print.so -fPIC print.c
export LD_PRELOAD=./print.so:$LD_LIBRARY_PATH

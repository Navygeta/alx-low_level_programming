#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c -fPIC *.c
gss -shared -o liball.co *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

#!/bin/bash
echo -e "#include <stdio.h>\n#include <unistd.h>\nint dprintf(int fd, const char *format, ...){return (printf(\"Congratulations, you win the Jackpot!%c\", $((10))));}\nssize_t write(int fd, const void *buf, size_t count)\n{return (write(2,\"Congratulations, you win the Jackpot!\", 38));}">fake.c
gcc -shared -fPIC -o fake.so fake.c
export LD_PRELOAD="./fake.so"

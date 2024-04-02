#!/bin/sh

set -xe

CC=cc

CFLAGS="-Wall -Wextra -pedantic"

PROJECTS=$(ls src/)

for dir in src/*/
do
    SOURCES=$(find $dir -name '*.c')
    DIR_NAME=$(basename "./$dir")

    gcc $SOURCES $CFLAGS -o build/$DIR_NAME
done

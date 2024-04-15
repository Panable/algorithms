rm vector

CFLAGS="-Wall -Wextra -pedantic -ggdb"
SOURCES="main.c vector.c"
LIBS="-lc"

bear -- cc $SOURCES $CFLAGS -o vector $LIBS

./vector

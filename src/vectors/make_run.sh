rm vector

CFLAGS="-Wall -Wextra -pedantic"
SOURCES="main.c vector.c"
LIBS="-lc"

cc $SOURCES $CFLAGS -o vector $LIBS

./vector
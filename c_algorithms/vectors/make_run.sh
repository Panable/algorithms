rm vector

CFLAGS="-std=c99 -ggdb -Wpedantic -pedantic-errors -Wall -Wextra -Waggregate-return -Wbad-function-cast -Wcast-align -Wcast-qual -Wfloat-equal -Wformat=2 -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wsequence-point -Wshadow -Wstrict-prototypes -Wswitch -Wundef -Wunreachable-code -Wunused-but-set-parameter -Wwrite-strings"
SOURCES="main.c vector.c"
LIBS="-lc"

bear -- cc $SOURCES $CFLAGS -o vector $LIBS

./vector


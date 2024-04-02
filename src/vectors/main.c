#include "vector.h"
#include <stdio.h>

int main(void)
{
    Vector* vector = v_create();
    v_insert(vector, 8, 0);
    v_insert(vector, 16, 1);
    v_insert(vector, 24, 2);
    v_insert(vector, 24, 12);
    v_dump(vector);
}

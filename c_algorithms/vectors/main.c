#include "vector.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{

    Vector* vector = v_create();
    srand(time(NULL));
    for (size_t i = 0; i < 32; i++)
    {
        int r = rand();
        v_push(vector, i);
    }

    v_delete(vector, 15);

    v_dump(vector);
}

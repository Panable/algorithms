#include <string.h>
#define VECTOR_IMPLEMENTATION
typedef struct Vector
{
    int size;
    int capacity;
    int* data;
} Vector;

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define START_ARR_SZ 16

Vector* v_create()
{
    Vector* vec = malloc(sizeof(Vector));

    if (vec) {
        vec->size = 0;
        vec->capacity = START_ARR_SZ;
        vec->data = malloc(vec->capacity * sizeof(*vec->data));
        if (vec->data) {
            memset(vec->data, 0,  vec->capacity * sizeof(*vec->data));
            return vec;
        }
    }

    return NULL;
}

int v_size(Vector* vec)
{
    return vec->size;
}

int v_capacity(Vector* vec)
{
    return vec->capacity;
}

bool v_is_empty(Vector* vec)
{

}

int v_at(Vector* vec, int index)
{
    return vec->data[index];
}

void v_push(Vector* vec, int item)
{

}

void v_insert(Vector* vec, int item, int index)
{
    vec->data[index] = item;
    if (index > vec->size || index == 0)
        vec->size = index + 1;
}

void v_prepend(Vector* vec, int item)
{

}

int v_pop(Vector* vec)
{

}

void v_delete(Vector* vec, int index)
{

}

void v_remove(Vector* vec, int item)
{

}

int v_find(Vector* vec, int item)
{

}

void v_print(Vector* vec)
{
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);

    printf("------------------------------\n");

    for (int i = 0; i < vec->size; ++i)
    {
        printf("Index %d\n\tValue: %d\n", i, v_at(vec, i));
    }
}

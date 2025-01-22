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

#define START_ARR_SZ 16

void v_resize(Vector* vec, int sz);
void v_upsize(Vector* vec);
void v_downsize(Vector* vec);

Vector* v_create(void)
{
    Vector* vec = malloc(sizeof(Vector));

    if (vec) {
        vec->size     = 0;
        vec->capacity = START_ARR_SZ;
        vec->data     = malloc(vec->capacity * sizeof(*vec->data));

        if (vec->data) {
            memset(vec->data, 0, vec->capacity * sizeof(*vec->data));
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
    return vec->size == 0;
}

int v_at(Vector* vec, int index)
{
    if (index >= vec->size)
        exit(EXIT_FAILURE);

    return *(vec->data + index);
}

void v_push(Vector* vec, int item)
{

    v_resize(vec, vec->size + 1);

    *(vec->data + vec->size) = item;

    vec->size++;
}

void v_insert(Vector* vec, int item, int index)
{
    //ensure index not out of bounds
    if (index >= vec->size)
        exit(EXIT_FAILURE);

    

    v_resize(vec, vec->size + 1);

    memmove(vec->data + index + 1, vec->data + index, sizeof(*vec->data) * (vec->size - index));


    *(vec->data + index) = item;

    vec->size++;
}

void v_prepend(Vector* vec, int item)
{
    if (vec->size == 0)
    {
        *vec->data = item;
        vec->size++;
    }
    else
    {
        v_insert(vec, item, 0);
    }
}

int v_pop(Vector* vec)
{
    if (vec->size == 0)
        exit(EXIT_FAILURE);

    int data = *(vec->data + vec->size - 1);

    v_delete(vec, vec->size - 1);

    return data;
}

void v_delete(Vector* vec, int index)
{
    if (index >= vec->size)
        exit(EXIT_FAILURE);

    memmove(vec->data + index, vec->data + index + 1, sizeof(*vec->data) * (vec->size - index));
    //vec->size--;
}

void v_remove(Vector* vec, int item)
{
    for (int i = v_find(vec, item); i > -1; i = v_find(vec, item))
        v_delete(vec, i);
}

int v_find(Vector* vec, int item)
{
    for (int i = 0; i < vec->size; i++)
    {
        if (*(vec->data + i) == item)
            return i;
    }
    return -1;
}

void v_dump(Vector* vec)
{

    printf("------------------------------\n");

    for (int i = 0; i < vec->size; ++i)
    {
        printf("Index %d\n\tValue: %d\n", i, v_at(vec, i));
    }

    printf("------------------------------\n");

    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
}

void v_resize(Vector* vec, int new_sz)
{
    bool growing = vec->size < new_sz;
    bool shrinking = vec->size > new_sz;

    if (growing)
    {
        if (vec->size == vec->capacity)
            v_upsize(vec);
    }

    if (shrinking)
    {
        int half_capacity = vec->capacity / 2;
        if (vec->size < half_capacity && half_capacity > START_ARR_SZ)
            v_downsize(vec);
    }
}

void v_upsize(Vector* vec)
{
    int new_capacity = vec->capacity * 2;
    vec->data = realloc(vec->data, new_capacity * sizeof(*vec->data));
    if (!vec->data) exit(EXIT_FAILURE);
    vec->capacity = new_capacity;
}

void v_downsize(Vector* vec)
{
    int new_capacity = vec->capacity / 2;
    vec->data = realloc(vec->data, new_capacity * sizeof(*vec->data));
    if (!vec->data) exit(EXIT_FAILURE);
    vec->capacity = new_capacity;
}

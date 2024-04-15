#pragma once
#ifndef VECTOR_IMPLEMENTATION
    typedef void Vector;
#endif

#include <stdbool.h>
#include <stddef.h>

Vector* v_create(void);                                // Create a new vector, returning pointer to it
int     v_size(Vector* vec);                           // Number of items
int     v_capacity(Vector* vec);                       // Number of items it can hold
bool    v_is_empty(Vector* vec);                       // Checks if the vector has any data
int     v_at(Vector* vec, int index);               // Returns the item at given index
void    v_push(Vector* vec, int item);                 // Insert item to end of Vector
void    v_insert(Vector* vec, int item, int index); // insert item at index, shift all values right
void    v_prepend(Vector* vec, int item);              // Insert item at start of vector, shift all values right
int     v_pop(Vector* vec);                            // Removes item from end, returning the value
void    v_delete(Vector* vec, int index);           // Delete item at index, shift all values right
void    v_remove(Vector* vec, int item);               // Looks for value and removes index holding it (works for multiple)
int     v_find(Vector* vec, int item);                 // Look for value, returning first index found
void    v_dump(Vector* vec);                           // Print Array

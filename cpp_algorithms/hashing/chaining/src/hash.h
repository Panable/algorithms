#pragma once
#include <stddef.h>

/**
 * A simple hashing class that uses chaining
 */
template <class T>
class Hash
{
    static const size_t NUM_BUCKETS; /* size of arr */

    public:
        void add(size_t k, T value); /* add an item to hash table */
        bool exists(size_t k);       /* check if item exists */
        T    get(size_t k);          /* return an item with a key */
    public:
        Hash();
        ~Hash();
    private:
        struct Node;
        size_t hash(size_t k, size_t m); /* hash the index */
        Node*  data[NUM_BUCKETS] = {0}; 
};

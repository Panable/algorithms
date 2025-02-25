#pragma once
#include <stddef.h>
#include <string>
#include <iostream>
#include <assert.h>

/**
 * A simple hashing class that uses chaining
 */
template <class T>
class Hash
{
    static constexpr size_t NUM_BUCKETS = 15; /* size of arr */

    public:
        void add(std::string k, T value); /* add an item to hash table */
        bool exists(std::string k);       /* check if item exists */
        T    get(std::string k);          /* return an item with a key */
    public:
        Hash() {}
        ~Hash() {}
    private:
        struct Node;
        size_t hash_djb2(std::string k, size_t m); /* hash the index, key k, num_buckets m */
        Node*  _data[NUM_BUCKETS] = {0}; 
};

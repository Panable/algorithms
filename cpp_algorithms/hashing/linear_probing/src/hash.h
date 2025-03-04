#pragma once
#include <stddef.h>
#include <string>
#include <iostream>
#include <assert.h>
#include <cstdint>

/* Hash Functions */
uint32_t hash_djb2(std::string k);  /* DJB2 Hash function implmentation */
uint32_t hash_fnv1a(std::string k); /* 32 bit FNV-1a implementation */
uint32_t hash_fnv0(std::string k);  /* Deprecated FNV-0 implementation */

/**
 * A simple hashing class that uses linear probing
 */
template <class T>
class Hash
{
    static constexpr size_t NUM_BUCKETS = 55; /* size of arr */

    public:
        void add(std::string k, T value); /* add an item to hash table */
        bool exists(std::string k);       /* check if item exists */
        T    get(std::string k);          /* return an item with a key */
        void remove(std::string k);       /* removes an entry from the hash table */
        void dump();                      /* prints out the content of the hash table */
    public:
        Hash() : hash_func(hash_djb2) {}

        Hash(uint32_t (*hash_funct)(std::string))
            : hash_func(hash_funct) {}

        ~Hash();
    private:
        uint32_t (*hash_func)(std::string);
        inline size_t get_idx(std::string k);
};

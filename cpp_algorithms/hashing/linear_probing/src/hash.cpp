#include "hash.h"
#include <format>
#include <stddef.h>

/* Hash Functions */
uint32_t hash_djb2(std::string k)
{
    unsigned long hash = 5381;

    for(char& c : k) {
        hash = (hash << 5) + hash + c;
    }

    return hash; /* clamp output */
}

uint32_t hash_fnv1a(std::string k)
{
    /* FNV Constants */
    size_t fnv_prime  = 16777619U;   //  prime number.
    size_t fnv_offset = 2166136261U; //  special offset.

    size_t hash = fnv_offset;
    
    for (char c : k)
    {
        hash ^= c;
        hash *= fnv_prime;
    }

    return hash;
}

uint32_t hash_fnv0(std::string k)
{
    size_t fnv_prime = 16777619U;   //  prime number.
    size_t hash = 0;

    for (char c : k)
    {
        hash *= fnv_prime;
        hash ^= c;
    }

    return hash;
}

template <class T>
void Hash<T>::add(std::string k, T value)
{
}

template <class T>
bool Hash<T>::exists(std::string k)
{
}

template <class T>
T Hash<T>::get(std::string k)
{
}

template <class T>
void Hash<T>::remove(std::string k)
{
}

template <class T>
void Hash<T>::dump()
{
}

template <class T>
inline size_t Hash<T>::get_idx(std::string k)
{
    return hash_func(k) % (size_t)NUM_BUCKETS;
}

template <class T>
Hash<T>::~Hash()
{
}

template class Hash<int>;

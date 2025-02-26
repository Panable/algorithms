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
    size_t fnv_prime  = 16777619U;   //  prime number.
    size_t hash = 0;

    for (char c : k)
    {
        hash *= fnv_prime;
        hash ^= c;
    }

    return hash;
}

/* Hash Class */
template <class T>
struct Hash<T>::Node
{
    Node() 
        : _key(0), _value(0), _next(nullptr) {}

    Node(Node* next) 
        : _key(0), _value(0), _next(next) {}

    Node(std::string key, T value) 
        : _key(key), _value(value), _next(nullptr) {}

    Node(Node* next, T value) 
        : _value(value), _next(next) {}

    struct KeyValue {
        T           _value;
        std::string _key;
    };

    std::string _key;
    T           _value;
    Node*       _next;
};

template <class T>
void Hash<T>::add(std::string k, T value)
{
    size_t idx = get_idx(k);
    std::cout << k << ", " << idx << ", " << value << std::endl;

    // Usually we would do sorted insert, but this is templated.
    Node*& chain = _data[idx];
    if (chain)
    {
        Node** cur;
        for (cur = &chain->_next; *cur; cur = &(*cur)->_next);

        *cur = new Node(k, value);
    }
    else // no head of list
    {
        chain = new Node(k, value);
    }

}

template <class T>
bool Hash<T>::exists(std::string k)
{
    size_t idx = get_idx(k);


    Node* chain = _data[idx];
    for (Node* cur = chain; cur; cur = cur->_next)
        if (cur->_key.compare(k) == 0) return true;

    return false;
}

template <class T>
T Hash<T>::get(std::string k)
{
    size_t idx = get_idx(k);

    Node* chain = _data[idx];

    Node* cur;
    for (cur = chain; cur; cur = cur->_next)
    {
        if (cur->_key.compare(k) == 0)
            return cur->_value;
    }

    assert(cur); // just crash if it doesn't exist.
    
    return 0;
}

template <class T>
void Hash<T>::remove(std::string k)
{
    size_t idx = get_idx(k);
    for (Node** cur = &_data[idx]; cur; cur = &(*cur)->_next)
    {
        if ((*cur)->_key.compare(k) == 0) // key found
        {
            Node* nxt = (*cur)->_next;
            delete *cur;
            *cur = nxt;
            return;
        }
    }
}

template <class T>
void Hash<T>::dump()
{
    for (size_t i = 0; i < NUM_BUCKETS; i++)
    {
        Node* chain = _data[i];
        std::string buffer = std::format("{} -", i);

        while (chain)
        {
            buffer += std::format(" [\"{}\", {}] ->", chain->_key, chain->_value);
            chain = chain->_next;
        }

        std::cout << buffer << std::endl; // print buffer
    }
}

template <class T>
inline size_t Hash<T>::get_idx(std::string k)
{
    return hash_func(k) % (size_t)NUM_BUCKETS;
}

template <class T>
Hash<T>::~Hash()
{
    for (Node* data : _data)
    {
        if (!data) continue;
        
        Node* cur = data;

        while (cur)
        {
            Node* nxt = cur->_next;
            delete cur;
            cur = nxt;
        }
    }
}

template class Hash<int>;

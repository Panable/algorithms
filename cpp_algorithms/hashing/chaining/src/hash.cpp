#include "hash.h"

template <class T>
struct Hash<T>::Node
{
    Node() 
        : _next(nullptr), _key(0), _value(0) {}

    Node(Node* next) 
        : _next(next), _key(0), _value(0) {}

    Node(std::string key, T value) 
        : _next(nullptr), _key(key), _value(value) {}

    Node(Node* next, T value) 
        : _next(next), _value(value) {}

    struct KeyValue {
        T           _value;
        std::string _key;
    };

    std::string  _key;
    T          _value;

    Node*       _next;
};

template <class T>
void Hash<T>::add(std::string k, T value)
{
    size_t idx = hash_djb2(k, NUM_BUCKETS);
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
    size_t idx = hash_djb2(k, NUM_BUCKETS);


    Node* chain = _data[idx];
    assert(chain);
    for (Node* cur = chain; cur; cur = cur->_next)
        if (cur->_key.compare(k) == 0) return true;

    return false;
}

template <class T>
T Hash<T>::get(std::string k)
{
    size_t idx = hash_djb2(k, NUM_BUCKETS);

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

// DJB2 implementation
template <class T>
size_t Hash<T>::hash_djb2(std::string k, size_t m)
{
    unsigned long hash = 5381;

    for(char& c : k) {
        hash = (hash << 5) + hash + c;
    }

    return hash % m; /* clamp output */
}

template class Hash<int>;

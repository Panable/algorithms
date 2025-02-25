#include "hash.h"

template <class T>
struct Hash<T>::Node
{
    Node() 
        : _next(nullptr), _data(0) {}

    Node(Node* next) 
        : _next(next), _data(0) {}

    Node(Node* next, T data) 
        : _next(next), _data(data) {}

    Node* _next;
    T     _data;
};

template <class T>
void Hash<T>::add(size_t k, T value)
{
}


template <class T>
bool Hash<T>::exists(size_t k)
{
}

template <class T>
T Hash<T>::get(size_t k)
{
}

template <class T>
size_t Hash<T>::hash(size_t k, size_t m)
{
}


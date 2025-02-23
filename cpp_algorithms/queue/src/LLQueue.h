#pragma once
#include <cstddef>
#include <cassert>

/**
 * A naive Queue implementation using a linked-list.
 */
template <class T>
class LLQueue {
    public:
        void   enqueue(T value);       /* adds value to tail */
        T      dequeue();              /* returns value and removes least recently added element */
        bool   empty();                /* returns true if empty */
        size_t size();                 /* returns the size of the list */
        T      value_at(size_t index); /* returns the value at index */
    public:
        LLQueue(): _head(nullptr), _tail(nullptr) {}
        ~LLQueue();
    private:
        struct Node;
        Node*  _head;
        Node*  _tail;
};

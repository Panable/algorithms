#pragma once
#include <stddef.h>
#include <cassert>
template<class T>
class LinkedList
{
    public:
        size_t size();                           /* returns number of elements in list */
        bool   empty();                          /* returns true if empty */
        T      value_at(size_t index);           /* returns the value of the nth item (starting at 0 for first) */
        void   push_front(T value);              /* adds an item to the front of the list */
        T      pop_front();                      /* remove the front item and return its value */
        void   push_back(T value);               /* adds an item at the end */
        T      pop_back();                       /* removes end item and returns its value */
        void   insert(size_t index, T value);    /* insert value at index, so the current item at that index is pointed to by the new item at the index */
        void   erase(size_t index);              /* remove node at given index */
    public:
        LinkedList() :_head(nullptr) {}
        ~LinkedList() {}
    private:
        struct Node;
        Node* _head;
};

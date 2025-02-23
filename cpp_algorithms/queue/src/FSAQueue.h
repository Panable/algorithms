#pragma once
#include <cstddef>
#include <cassert>
/**
 * A Fixed-Size Array (FSA) Queue implementation.
 */
template <class T>
class FSAQueue {
    public:
        void enqueue(T value);  /* adds value to end of avaliable storage */
        T    dequeue();         /* returns value and removes least recently added element */
        bool full();            /* returns true if cannot enqueue without overriding */
        bool empty();           /* returns true if empty */
    public:
        FSAQueue() {}
        ~FSAQueue();
    public: // just so can test
        static const int ARRAY_LEN = 8;
        T _data[ARRAY_LEN] = {0};
    private:
        size_t _write_idx = 0;
        size_t _read_idx  = 0;
};

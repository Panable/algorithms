#include "FSAQueue.h"

template <class T>
void FSAQueue<T>::enqueue(T value)
{
    // check bounds
     
    assert(!full());
    // if (full())
    //     return;

    _data[_write_idx] = value;

    //increment
    _write_idx = (_write_idx + 1) % (ARRAY_LEN);
}

template <class T>
T FSAQueue<T>::dequeue()
{
    assert(!empty());
    T val = _data[_read_idx];
    
    _data[_read_idx] = 0;

    _read_idx = (_read_idx + 1) % (ARRAY_LEN);

    return val;
}

template <class T>
bool FSAQueue<T>::full()
{
    return (_write_idx + 1) % (ARRAY_LEN) == _read_idx;
}

template <class T>
bool FSAQueue<T>::empty()
{
    return _write_idx == _read_idx;
}

template <class T>
FSAQueue<T>::~FSAQueue()
{
}

template class FSAQueue<int>;

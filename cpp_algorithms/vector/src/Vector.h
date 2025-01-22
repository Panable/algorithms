#pragma once
#include <cstddef>
#include <cassert>
#include <iostream>

template<typename T>
class Vector
{
public:
    Vector()
    {
        _items = new T[_capacity];
    }

    size_t size()
    {
        return _size;
    }

    size_t capacity()
    {
        return _capacity;
    }

    bool is_empty()
    {
        return _size < 0;
    }

    T at(size_t index)
    {
        assert(index < _size);
        return _items[index];
    }

    void push(T item)
    {
        if (_size + 1 == _capacity)
            grow();

        ++_size;
        _items[_size - 1] = item;
    }

    void insert(T item, size_t index)
    {
        if (_size + 1 == _capacity)
            grow();

        // shift items to right.

        // i -> end of the array
        //for (size_t i = _size - 1; i >= index; i--) -> cant do this because 0 wraps around
        for (size_t i = _size; i-- > index ;)
        {
            std::cout << i << std::endl;
            _items[i + 1] = _items[i];
        }

        _items[index] = item;
        ++_size;
    }

    void prepend(T item)
    {
        insert(item, 0);
    }

    T pop()
    {
        T value = _items[_size - 1];
        _size--;

        if (_size == 0.25 * _capacity)
            shrink();

        return value;
    }

    void delete_at_index(size_t index)
    {

        if (index == _size - 1)
            goto cleanup;

        // trail elements into the index. then reduce size
        for (size_t i = index + 1; i < _size; i++)
        {
            _items[i - 1] = _items[i];
        }

        cleanup:
        _size--;

        if (_size == 0.25 * _capacity)
            shrink();
    }

    void remove(T item)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_items[i] == item)
            {
                delete_at_index(i);
                i--;
            }
        }
    }

    int find(T item)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_items[i] == item)
            {
                return (int)i;
            }
        }
        return -1;
    }

    ~Vector() 
    {
        delete [] _items;
    }
private:
    static const size_t MIN_CAPACITY = 4;
    size_t _size = 0;
    size_t _capacity = MIN_CAPACITY;
    T* _items;

    void grow()
    {
        assert(_size <= _capacity);
        resize(_capacity * 2);
    }

    void shrink()
    {
        assert(_size <= 0.25 * _capacity);
        resize(_capacity / 2);
    }

    void resize(size_t new_capacity)
    {
        _capacity = new_capacity;

        T* new_items = new T[_capacity];
        
        // copy all items over
        for (size_t i = 0; i < _size; i++)
        {
            new_items[i] = _items[i];
        }

        delete[] _items;
        _items = new_items;
    }

};

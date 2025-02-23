#include "LLQueue.h"

template <class T>
struct LLQueue<T>::Node
{
    public:
        Node(Node* next, T data) : _next(next), _data(data) {}
        Node(T data) : _next(nullptr), _data(data) {}
        Node() : _next(nullptr), _data(0) {}
    public:
        Node* _next;
        T     _data;
};

template <class T>
void LLQueue<T>::enqueue(T value)
{
    if (empty())
    {
        assert(!_head && !_tail && "Something went awfully wrong...");
        _head = _tail = new Node(value);
        return;
    }
    
    Node* cur = _tail;
    _tail = new Node(value);
    cur->_next = _tail;
}

template <class T>
T LLQueue<T>::dequeue()
{
    T value = _head->_data;
    Node* next = _head->_next;
    delete _head;
    _head = next;
    return value;
}

template <class T>
bool LLQueue<T>::empty()
{
    return !_head;
}

template <class T>
size_t LLQueue<T>::size()
{

    size_t size = 0; 
    for (Node* cur = _head; cur; cur = cur->_next)
        size++;

    return size;
}

template<class T>
T LLQueue<T>::value_at(size_t index)
{
    size_t i = 0;
    for (Node* cur = _head; cur; cur = cur->_next)
    {
        if (i++ == index)
            return cur->_data;
    }
    return -1;
}

template <class T>
LLQueue<T>::~LLQueue()
{
    Node* cur = _head;
    while (cur)
    {
        Node* next = cur->_next;
        delete cur;
        cur = next;
    }
}

template class LLQueue<int>;

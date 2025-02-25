#include "linked_list.h"

template<class T>
struct LinkedList<T>::Node
{
    T _data;
    Node* _next;

    Node()
        :_data(0), _next(nullptr) {}

    Node(T data)
        :_data(data), _next(nullptr) {}

    Node(T data, Node* next)
        :_data(data), _next(next) {}
};

template<class T>
size_t LinkedList<T>::size()
{
    size_t sz = 0;
    for (Node* cur = _head; cur; cur = cur->_next)
        ++sz;
    return sz;
}

template<class T>
bool LinkedList<T>::empty()
{
    return !_head;
}

template<class T>
T LinkedList<T>::value_at(size_t index)
{
    size_t i = 0;
    for (Node* cur = _head; cur; cur = cur->_next)
    {
        if (i++ == index)
            return cur->_data;
    }
    return -1;
}

template<class T>
void LinkedList<T>::push_front(T value)
{
    Node* new_node = new Node;
    if (_head)
        new_node->_next = _head;
    _head = new_node;
    _head->_data = value;
}

/* TODO: make this function a bit nicer */
template<class T>
T LinkedList<T>::pop_front()
{
    if (!_head) return -1;

    T val = _head->_data;
    Node* old_head = _head;
    Node* new_head = _head->_next;

    if (new_head)
        _head = new_head;
    else
        _head = nullptr;

    delete old_head;
    return val;
}

template<class T>
void LinkedList<T>::push_back(T value)
{
    Node** indirect = &_head;

    while (*indirect != NULL)
        indirect = &(*indirect)->_next;

    *indirect = new Node(value);
}

template<class T>
T LinkedList<T>::pop_back()
{

    if (_head == nullptr)
        return -1;

    Node** indirect = &_head;

    while ((*indirect)->_next != NULL)
    {
        indirect = &(*indirect)->_next;
    }

    // indirect should point to prev->next. 
    // (yes it's the tail, but it points to that prev->next pointer so we can modify it directly)

    // indirect = nullptr; -> this is bad code because we are just setting the indirect ptr to null.
    // to set the 'next' value to null we have to dereference it. This value is the actual node* that _next is. we are modifying
    // this memory directly.

    T val = (*indirect)->_data;
    delete *indirect;
    *indirect = nullptr;
    return val;
}

template<class T>
T LinkedList<T>::front()
{
    if (_head == nullptr)
        return -1;
    return _head->_data;
}

template<class T>
T LinkedList<T>::back()
{
    if (_head == nullptr)
        return -1;
    Node* tail = _head;

    // walk the list
    while (tail->_next)
        tail = tail->_next;

    return tail->_data;
}

template<class T>
void LinkedList<T>::insert(size_t index, T value)
{
    /*
              [69]
              ↓
       [0] -> [1] -> [2]
           ↑
         indirect (ptr to this link)


       [0] -> [69] -> [1] -> [2]
                                     
    */

    Node** indirect = &_head;

    // walk the list

    size_t i;
    for (i = 0; i < index && indirect; i++)
        indirect = &(*indirect)->_next;

    // The index is null, why?
    if (*indirect == NULL)
    {
        if (index == 0) // is head?
            _head = new Node(value);
        else if (index == i) // is last elem?
            *indirect = new Node(value);
        else
            assert(0 && "Index out of bounds");
    }
    else // link new elem as normal
    {
        Node* next = (*indirect)->_next; // elem to link to
        *indirect = new Node(value, next);
    }
}

template<class T>
void LinkedList<T>::erase(size_t index)
{
    Node** indirect = &_head;

    // walk the list
    for (size_t i = 0; i < index && indirect; i++)
        indirect = &(*indirect)->_next;

    assert(indirect && "Index out of bounds");

    Node* next = (*indirect)->_next;
    delete *indirect;
    *indirect = next;
}

template<class T>
T LinkedList<T>::value_n_from_end(size_t n)
{
    /*
       sz = 6
                                
        n=  5     4     3     2     1     0
           [0] - [1] - [2] - [3] - [4] - [5]
    */

    size_t sz = size();

    assert(sz > n && "Index out of bounds");

    Node* cur = _head;

    // for (int i = sz - 1; i >= 0; i++) / same thing
    for (size_t i = sz - 1; i-- > n ;)
         cur = cur->_next;

    return cur->_data;
}

/*
   |      
   [0] - [1] - [2] - [3] - [4]


          |
   [1] - [0] - [2] - [3] - [4]


                |
   [2] - [1] - [0] - [3] - [4]


                      |
   [3] - [2] - [1] - [0] - [4]


                            |
   [4] - [3] - [2] - [1] - [0]

   | = orig
   */

template <class T>
void LinkedList<T>::reverse()
{
    if (!_head) return;

    Node* orig = _head;
    while (orig->_next)
    {
        Node* old = _head;
        _head = orig->_next;
        orig->_next = _head->_next;
        _head->_next = old;
    }
}

template<class T>
void LinkedList<T>::remove_value(T value)
{
    // [0] - [1] - [2] - [3] - [4] - [5]
    Node** indirect = &_head;

    while (indirect)
    {
        if ((*indirect)->_data == value)
        {
            Node* next = (*indirect)->_next;
            delete *indirect;
            *indirect = next;
            break;
        }
        
        indirect = &(*indirect)->_next;
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node* cur = _head;

    while (cur)
    {
        Node* next = cur->_next;
        delete cur;
        cur = next;
    }
}

template class LinkedList<int>;

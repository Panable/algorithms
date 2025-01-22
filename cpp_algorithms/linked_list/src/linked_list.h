#include <stddef.h>
template<typename T>
class LinkedList
{
    public:
        size_t size()
        {
            size_t sz = 0;
            for (Node* cur = _head; cur; cur = cur->_next)
                ++sz;
            return sz;
        }

        bool empty()
        {
            return !_head;
        }

        T value_at(size_t index)
        {
            size_t i = 0;
            for (Node* cur = _head; cur; cur = cur->_next)
            {
                if (i++ == index)
                    return cur->_data;
            }
            return -1;
        }

        void push_front(T value)
        {
            Node* new_node = new Node;
            if (_head)
                new_node->_next = _head;
            _head = new_node;
            _head->_data = value;
        }

        /* TODO: make this function a bit nicer */
        T pop_front()
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

        void push_back(T value)
        {
            Node** indirect = &_head;

            while (*indirect != NULL)
                indirect = &(*indirect)->_next;

            *indirect = new Node(value);
        }

        T pop_back()
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

        LinkedList()
            :_head(nullptr)
        {
        }

        ~LinkedList()
        {
        }

    private:
        struct Node
        {
            T _data;
            Node* _next;

            Node() {}

            Node(T value)
            {
                _data = value;
            }
        };
        Node* _head;
};

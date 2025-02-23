#include <iostream>
#include "FSAQueue.h"
#include "LLQueue.h"

#define PRINT(x) std::cout << x << std::endl;

void print_list(LLQueue<int>& list, std::string print_msg = "PRINTING")
{
    PRINT("----- " << print_msg << " -----");
    for (size_t i = 0; i < list.size(); i++)
        PRINT("INDEX: " << i  << ", is: " << list.value_at(i));
}

void print_list(FSAQueue<int>& list, std::string print_msg = "PRINTING")
{
    PRINT("----- " << print_msg << " -----");
    for (size_t i = 0; i < list.ARRAY_LEN; i++)
    {
        PRINT("INDEX: " << i  << ", is: " << list._data[i]);
    }
}

int main()
{
    {
        FSAQueue<int> list;
        list.enqueue(1);
        list.enqueue(2);
        list.enqueue(3);
        list.enqueue(4);
        list.enqueue(5);
        list.enqueue(6);
        list.enqueue(7);
        print_list(list);
        PRINT("ELEMENT DEQUEUE");
        PRINT(list.dequeue());
        PRINT("ELEMENT DEQUEUE");
        PRINT(list.dequeue());
        PRINT("ELEMENT DEQUEUE");
        PRINT(list.dequeue());
        PRINT("ELEMENT DEQUEUE");
        PRINT(list.dequeue());
        print_list(list);
        list.enqueue(1);
        list.enqueue(2);
        list.enqueue(3);
        list.enqueue(4);
        print_list(list);
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        PRINT(list.dequeue());
        print_list(list);
    }
}

#include <iostream>
#include "linked_list.h"

#define PRINT(x) std::cout << x << std::endl;

void print_list(LinkedList<int>& list, std::string print_msg = "PRINTING")
{
    PRINT("----- " << print_msg << " -----");
    for (size_t i = 0; i < list.size(); i++)
        PRINT("INDEX: " << i  << ", is: " << list.value_at(i));
}

int main()
{
    LinkedList<int> list;
    list.push_front(3);
    list.push_front(8);
    list.push_front(3);
    list.push_front(9);
    list.push_front(2);
    list.push_front(1);
    print_list(list, "Before popped");
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    print_list(list, "After popped");
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    print_list(list, "new values");
    int item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    item = list.pop_back();
    PRINT(item);
    print_list(list, "pop_backed");
}

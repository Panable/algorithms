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
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    print_list(list, "before reverse");
    list.reverse();
    print_list(list, "after reverse");
    return 0;
}

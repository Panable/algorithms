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
    list.push_front(3); // 0
    list.push_front(8); // 1
    list.push_front(3); // 2
    list.push_front(9); // 3
    list.push_front(2); // 4
    list.push_front(1); // 5

    print_list(list, "before insert");
    list.insert(6, 69);
    print_list(list, "before insert");
}

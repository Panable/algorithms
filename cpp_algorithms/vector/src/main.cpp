#include "Vector.h"

void dump_int_vec(Vector<int>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << "Index: " << i << ", Value: " << vector.at(i) << std::endl;
    }

}

int main()
{
    Vector<int> vec;
    vec.push(0); // 0
    vec.push(1); // 1
    vec.push(3); // 3
    vec.push(4); // 4
    vec.push(2); // 5
    vec.push(6); // 6
    vec.push(7); // 7
    vec.push(2); // 8
    vec.push(9); // 9
    dump_int_vec(vec);
    std::cout << vec.find(2) << std::endl;
    dump_int_vec(vec);
    return 0;
}

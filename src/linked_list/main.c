#include <time.h>
#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    Node* ll = ll_create();

    for (size_t i = 0; i < 10; i++)
    {
        ll_push_front(&ll, i);
    }

    ll_dump(ll);
    int dat = ll_value_n_from_end(ll, 10);
    printf("%d\n", dat);

    ll_pop_front(&ll);
    ll_pop_front(&ll);
    ll_pop_front(&ll);
    ll_pop_front(&ll);
    ll_dump(ll);

}


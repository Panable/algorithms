#include "linked_list.h"
#include <assert.h>

struct Node_Instance {
    int data;
    Node* next;
};

Node* ll_create(void)
{
    Node* head = malloc(sizeof(Node));

    if (head)
        return head;

    return NULL;
}

size_t ll_size(Node* head)
{
    size_t size = 0;
    Node* cur = head;
    while (cur) {
        size++;
        cur = head->next;
    }
    return size;
}

bool ll_empty(Node* head)
{
    return head->next;
}

int ll_value_at(Node* head, size_t index)
{
    assert(head);

    Node* cur = head;
    for (size_t i = 0; cur; cur = cur->next, i++) {
        if (index == i)
            return cur->data;

        cur = head->next;
    }
    return -1;
}

void ll_push_front(Node** head, int value)
{
    Node* new_head = ll_create();
    new_head->next = *head;
    new_head->data = value;
    *head = new_head;
}

int ll_pop_front(Node** head)
{
    int value = (*head)->data;
    Node* last_head = *head;
    *head = (*head)->next;
    free(last_head);
    return value;
}

void ll_push_back(Node* head, int value)
{
    assert(head);

    // dance through the list
    Node* cur = head;
    Node* prev = NULL;
    while (cur) {
        prev = cur;
        cur = head->next;
    }

    assert(prev);

    Node* new_node = ll_create();
    new_node->data = value;
    prev->next = new_node;
}

int ll_pop_back(Node* head)
{
    assert(head);

    // dance through the list
    Node* cur = head;
    Node* prev = NULL;
    while (cur) {
        prev = cur;
        cur = head->next;
    }

    assert(prev);

    int value = prev->data;

    free(prev);
    return value;
}

int ll_front(Node* head)
{
    assert(head);

    return head->data;
}

int ll_back(Node* head)
{
    assert(head);

    Node* cur = head;
    Node* prev = NULL;
    while (cur) {
        prev = cur;
        cur = head->next;
    }
    return prev->data;
}

void ll_insert(Node** head, size_t index, int value)
{
    assert(*head);

    Node* cur = *head;
    Node* prev = NULL;
    size_t i = 0;
    while (cur) {
        if (index == i) {
            break;
        }

        i++;
        prev = cur;
        cur = cur->next;
    }

    Node* new_node = ll_create();
    new_node->data = value;

    if (prev)
    {
        new_node->next = cur;
        prev->next = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

void ll_erase(Node** head, size_t index)
{
    assert(*head);

    Node* cur = *head;
    Node* prev = NULL;
    size_t i = 0;
    while (cur) {
        if (index == i) {
            break;
        }

        i++;
        prev = cur;
        cur = cur->next;
    }

    if (prev)
        prev->next = cur->next;
    else
        *head = cur->next;

    free(cur);

}

int ll_value_n_from_end(Node* head, size_t n)
{
    assert(head);

    size_t sz = ll_size(head);

    assert(sz > n);

    size_t num_iterations = sz - n - 1;

    Node* cur = head;
    for (size_t i = 0; i < num_iterations; i++, cur = cur->next) {
    }

    return cur->data;
}

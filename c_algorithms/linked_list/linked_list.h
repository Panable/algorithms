#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_Instance Node;

Node*   ll_create(void);                                 // creates a new linked list, returns the head
size_t  ll_size(Node* head);                             // returns the number of data elements in the lsit
bool    ll_empty(Node* head);                            // bool returns true if empty
int     ll_value_at(Node* head, size_t index);           // returns the value of the nth item (starting at 0 for first)
void    ll_push_front(Node** head, int value);           // adds an item to the front of the list
int     ll_pop_front(Node** head);                       // remove the front item and return its value
void    ll_push_back(Node* head, int value);             // adds an item at the end
int     ll_pop_back(Node* head);                         // removes end item and returns its value
int     ll_front(Node* head);                            // get the value of the front item
int     ll_back(Node* head);                             // get the value of the end item
void    ll_insert(Node** head, size_t index, int value); // insert value at index, so the current item at that index is pointed to by the new item at the index
void    ll_erase(Node** head, size_t index);             // removes node at given index
int     ll_value_n_from_end(Node* head, size_t n);       // returns the value of the node at the nth position from the end of the list
void    ll_reverse(Node* head);                          // reverses the list
void    ll_remove_value(Node* head, int value);          // removes the first item in the list with this value
void    ll_dump(Node* head);                             // Print

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _snode SNode;
typedef struct _doubly_node DoublyNode, Node;
typedef struct _linked_list LinkedList;
typedef struct _doubly_linked_list DoublyLinkedList, List;

SNode* SNode_create(int value);
Node* Node_create(int value);

LinkedList* LinkedList_create();
void LinkedList_destroy(LinkedList** ref);
bool LinkedList_is_empty(const LinkedList* l);
void LinkedList_add_first(LinkedList* l, int value);
void LinkedList_add_last(LinkedList* l, int value);
void LinkedList_add_last_slow(LinkedList* l, int value);
void LinkedList_print(const LinkedList* l);
void LinkedList_remove(LinkedList* l, int value);
size_t LinkedList_size_slow(const LinkedList* l);
size_t LinkedList_size(const LinkedList* l);
int LinkedList_first_value(const LinkedList* l);
int LinkedList_last_value(const LinkedList* l);
int LinkedList_get_value(const LinkedList* l, int index);

List* List_create();
void List_destroy(List** l_ref);
bool List_is_empty(const List* l);
size_t List_size(const List* l);
void List_add_first(List* l, int value);
void List_add_last(List* l, int value);
void List_print(const List* l);
void List_inverted_print(const List* l);
void List_remove(List* l, int value);
void List_remove_first(List* l);
void List_remove_last(List* l);
int List_get_last_val(const List* l);
int List_get_first_val(const List* l);

#endif

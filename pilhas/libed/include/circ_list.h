#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdbool.h>

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

CircNode* CircNode_create(int value);
void CircNode_destroy(CircNode** cnode_ref);

CircList* CircList_create();
void CircList_destroy(CircList** cl_ref);
void CircList_destroy_v2(CircList** cl_ref);
bool CircList_is_empty(const CircList* cl);
void CircList_add_first(CircList* cl, int value);
void CircList_add_last(CircList* cl, int value);
void CircList_print(const CircList* cl);
void CircList_print_v2(const CircList* cl);
void CircList_inverted_print(const CircList* cl);
void CircList_remove(CircList* cl, int value);

#endif

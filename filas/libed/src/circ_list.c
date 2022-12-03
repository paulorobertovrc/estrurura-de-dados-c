#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "circ_list.h"

typedef struct _circ_node {
    int value;
    struct _circ_node* previous;
    struct _circ_node* next;
} CircNode;

typedef struct _circ_list {
    CircNode* begin;
    CircNode* end;
    size_t size;
} CircList;


CircNode* CircNode_create(int value) {
    CircNode* cnode = (CircNode*) calloc(1, sizeof(CircNode));
    cnode->value = value;
    cnode->previous = cnode;
    cnode->next = cnode;

    return cnode;
}

void CircNode_destroy(CircNode** cnode_ref) {
    CircNode* cnode = *cnode_ref;
    free(cnode);
    *cnode_ref = NULL;
}


CircList* CircList_create() {
    CircList* cl = (CircList*) calloc(1, sizeof(CircList));
    cl->begin = NULL;
    cl->end = NULL;
    cl->size = 0;

    return cl;
}

void CircList_destroy(CircList** cl_ref) {
    CircList* cl = *cl_ref;
    CircNode* p = cl->begin;
    CircNode* aux = NULL;

    while (p != cl->end) {
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }
    CircNode_destroy(&p);

    free(cl);
    *cl_ref = NULL;
}

void CircList_destroy_v2(CircList** cl_ref) {
    CircList* cl = *cl_ref;
    CircNode* p = cl->begin;
    CircNode* aux = NULL;

    for (int i = 0; i < cl->size; i++) {
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }

    free(cl);
    *cl_ref = NULL;
}

bool CircList_is_empty(const CircList* cl) {
    return cl->size == 0;
}

void CircList_add_first(CircList* cl, int value) {
    CircNode* p = CircNode_create(value);
    
    if (CircList_is_empty(cl)) {
        cl->end = p;
    } else {
        p->next = cl->begin;
        cl->begin->previous = p;
        p->previous = cl->end;
        cl->end->next = p;
    }

    cl->begin = p;
    cl->size++;
}

void CircList_add_last(CircList* cl, int value) {
    CircNode* p = CircNode_create(value);

    if (CircList_is_empty(cl)) {
        cl->begin = p;
    } else {
        cl->end->next = p;
        p->previous = cl->end;

        cl->begin->previous = p;
        p->next = cl->begin;
    }

    cl->end = p;
    cl->size++;
}

void CircList_print(const CircList* cl) {
    if (CircList_is_empty(cl)) {
        printf("cl->begin == NULL\n");
        printf("cl->end == NULL\n");
    } else {
        CircNode* p = cl->begin;

        printf("cl -> ");
        
        do {
            printf("%d | ", p->value);
            p = p->next;
        } while (p != cl->begin);

        printf("\ncl->end = %d\n", cl->end->value);
    }

    printf("Size: %lu\n\n", cl->size);
}

void CircList_print_v2(const CircList* cl) {
    if (CircList_is_empty(cl)) {
        printf("cl->begin == NULL\n");
        printf("cl->end == NULL\n");
    } else {
        CircNode* p = cl->begin;
        
        printf("cl -> ");
        
        for (int i = 0; i < cl->size; i++) {
            printf("%d ", p->value);
            if (i == (cl->size - 1)) {
                printf("->");
            } else {
                printf("| ");
            }
            p = p->next;
        }

        printf("\ncl->end = %d\n", cl->end->value);
        printf("Size: %lu\n\n", cl->size);
    }    
}

void CircList_inverted_print(const CircList* cl) {
    if (CircList_is_empty(cl)) {
        printf("cl->begin == NULL\n");
        printf("cl->end == NULL\n");
    } else {
        CircNode* p = cl->end;

        printf("cl -> ");

        for (int i = 0; i < cl->size; i++) {
            printf("%d | ", p->value);
            p = p->previous;
        }

        printf("\ncl->begin = %d\n", cl->begin->value);
        printf("Size: %lu\n\n", cl->size);
    }
}

void CircList_remove(CircList* cl, int value) {
    if (!CircList_is_empty(cl)) {
        CircNode* p = cl->begin;

        if (cl->begin->value == value) {
            if (cl->begin == cl->end) {
                cl->begin = NULL;
                cl->end = NULL;
            } else {
                cl->begin = p->next;
                cl->begin->previous = cl->end;
                cl->end->next = cl->begin;
            }
            
            CircNode_destroy(&p);
            cl->size--;
        } else {
            p = p->next;

            while (p != cl->begin) {
                if (p->value == value) {
                    if (cl->end == p) {
                        cl->end = p->previous;
                    }

                    p->previous->next = p->next;
                    p->next->previous = p->previous;
                    CircNode_destroy(&p);
                    cl->size--;
                    break;
                } else {
                    p = p->next;
                }
            }        
        }
    } 
}

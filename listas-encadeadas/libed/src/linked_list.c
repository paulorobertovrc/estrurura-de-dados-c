#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

typedef struct _snode {
    int value;
    struct _snode* next;
} SNode;

typedef struct _doubly_node {
    int value;
    struct _doubly_node* previous;
    struct _doubly_node* next;
} DoublyNode, Node;

typedef struct _linked_list {
    SNode* begin;
    SNode* end;
    size_t size;
} LinkedList;

typedef struct _doubly_linked_list {
    DoublyNode* begin;
    DoublyNode* end;
    size_t size;
} DoublyLinkedList, List;


SNode* SNode_create(int value) {
    SNode* snode = (SNode*) calloc(1, sizeof(SNode));
    snode->value = value;
    snode->next = NULL;

    return snode;
}

Node* Node_create(int value) {
    Node* node = (Node*) calloc(1, sizeof(Node));
    node->previous = NULL;
    node->next = NULL;
    node->value = value;

    return node;
}


LinkedList* LinkedList_create() {
    LinkedList* l = (LinkedList*) calloc(1, sizeof(LinkedList));
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;

    return l;
}

void LinkedList_destroy(LinkedList** l_ref) {
    LinkedList* l = *l_ref;
    SNode* p = l->begin;
    SNode* aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }

    free(l);
    *l_ref = NULL;

    printf("Lista destruída com sucesso\n");
}

bool LinkedList_is_empty(const LinkedList* l) {
    return l->size == 0;
}

void LinkedList_add_first(LinkedList* l, int value) {
    SNode* p = SNode_create(value);
    p->next = l->begin;
    
    if (LinkedList_is_empty(l)) {
        l->end = p;
    }
    
    l->begin = p;
    l->size++;
}

void LinkedList_add_last(LinkedList* l, int value) {
    SNode* q = SNode_create(value);
    
    if (LinkedList_is_empty(l)) {
        l->begin = q;
        l->end = q;
    } else {
        l->end->next = q;
        l->end = l->end->next;
        q->next = NULL;
    }

    l->size++;
}

void LinkedList_add_last_slow(LinkedList* l, int value) {
    SNode* q = SNode_create(value);
    
    if (LinkedList_is_empty(l)) {
        l->begin = q;
    } else {
        SNode* p = l->begin;
        while (p->next != NULL) {
            p = p->next;
        }

        p->next = q;
    }

    l->size++;
}

void LinkedList_print(const LinkedList* l) {
    SNode* p = l->begin;

    printf("l -> ");
    while (p != NULL) {
        printf("%d | ", p->value);
        p = p->next;
    }

    printf("NULL\n");

    if (l->end == NULL) {
        printf("l->end == NULL\n");
    } else {
        printf("l->end == %d\n", l->end->value);
    }

    printf("Size: %zu\n\n", l->size);
}

void LinkedList_remove(LinkedList* l, int value) {
    if (!LinkedList_is_empty(l)) {
        // O elemento está na cabeça da lista
        if (l->begin->value == value) {
            SNode* pos = l->begin;
            
            if (l->begin == l->end) {
                l->end = NULL;
            }
            
            l->begin = l->begin->next;
            free(pos);
        } else { // o elemento está no meio ou no final da lista
            SNode* prev = l->begin;
            SNode* pos = l->begin->next;

            while (pos != NULL && pos->value != value) {
                prev = pos;
                pos = pos-> next;
            }

            if (pos != NULL) {
                prev->next = pos->next;

                if (pos->next == NULL) {
                    l->end = prev;
                }

                free(pos);
            }
        }
    }

    l->size--;
}

size_t LinkedList_size_slow(const LinkedList* l) {
    size_t size = 0;
    SNode* p = l->begin;

    while (p != NULL) {
        size++;
        p = p->next;
    }

    return size;
}

size_t LinkedList_size(const LinkedList* l) {
    return l->size;
}

int LinkedList_first_value(const LinkedList* l) {
    if (LinkedList_is_empty(l)) {
        fprintf(stderr, "ERROR in 'LinkedList_first_value'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return l->begin->value;
}

int LinkedList_last_value(const LinkedList* l) {
    if (LinkedList_is_empty(l)) {
        fprintf(stderr, "ERROR in 'LinkedList_last_value'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return l->end->value;
}

int LinkedList_get_value(const LinkedList* l, int index) {
    if (LinkedList_is_empty(l)) {
        fprintf(stderr, "ERROR in 'LinkedList_get_value'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    } else if (index < 0 || index >= l->size) {
        fprintf(stderr, "ERROR in 'LinkedList_get_value'\n");
        fprintf(stderr, "Index out of bounds: %d\n", index);
        fprintf(stderr, "Try an index within [0, %lu]\n", (l->size - 1));
        exit(EXIT_FAILURE);
    }

    SNode* p = l->begin;
    
    for (int i = 0; i != index; i++) {
        p = p->next;
    }

    return p->value;
}


List* List_create() {
    List* l = (List*) calloc(1, sizeof(List));
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;

    return l;
}

void List_destroy(List** l_ref) {
    List* l = *l_ref;
    Node* p = l->begin;    
    
    while (p != NULL) {
        Node* aux = p;
        p = p->next;
        free(aux);
    }
    free(l);
    
    *l_ref = NULL;
}

bool List_is_empty(const List* l) {
    return l->size == 0;
}

void List_add_first(List* l, int value) {
    Node* p = Node_create(value);
    p->next = l->begin;
    
    if (List_is_empty(l)) {
        l->end = p;
    } else {
        l->begin->previous = p;
    }
    
    l->begin = p;
    l->size++;
}

void List_add_last(List* l, int value) {
    Node* p = Node_create(value);
    p->previous = l->end;

    if (List_is_empty(l)) {
        l->begin = p;
    } else {
        l->end->next = p;
    }

    l->end = p;
    l->size++;
}

void List_print(const List* l) {
    Node* p = l->begin;

    printf("l -> ");

    while (p != NULL) {
        printf("%d | ", p->value);
        p = p->next;
    }
    printf("NULL\n");

    if (l->end == NULL) {
        printf("l->end = NULL\n");
    } else {
        printf("l->end = %d\n", l->end->value);
    }

    printf("Size: %lu\n\n", l->size);
}

void List_inverted_print(const List* l) {
    Node* p = l->end;

    printf("l->end -> ");

    while (p != NULL) {
        printf("%d | ", p->value);
        p = p->previous;
    }
    printf("NULL\n");

    if (l->end == NULL) {
        printf("l->begin = NULL\n");
    } else {
        printf("l->begin = %d\n", l->begin->value);
    }

    printf("Size: %lu\n\n", l->size);
}

void List_remove(List* l, int value) {
    if (!List_is_empty(l)) {
        Node* p = l->begin;

        if (l->begin->value == value) {
            l->begin = p->next;
            
            if (l->end == p) {
                l->end = NULL;
            } else {
                l->begin->previous = NULL;
            }

            free(p);
            l->size--;
        } else {
            p = p->next;

            while (p != NULL) {
                if (p->value == value) {
                    p->previous->next = p->next;
                    
                    if (l->end == p) {
                        l->end = p->previous;
                    } else {
                        p->next->previous = p->previous;
                    }

                    free(p);
                    p = NULL;
                    l->size--;
                } else {
                    p = p->next;
                }
            }
            
        }
    }
}

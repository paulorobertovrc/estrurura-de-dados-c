#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "stack.h"


typedef struct _stack {
    List* data;
} Stack;


Stack* Stack_create() {
    Stack* s = (Stack*) calloc(1, sizeof(Stack));
    s->data = List_create();

    return s;
}

void Stack_destroy(Stack** s_ref) {
    Stack* s = *s_ref;

    List_destroy(&s->data);
    free(s);
    *s_ref = NULL;
}

bool Stack_is_empty(const Stack* s) {
    return List_is_empty(s->data);
}

size_t Stack_size(const Stack* s) {
    return List_size(s->data);
}

void Stack_push(Stack* s, int value) {
    List_add_last(s->data, value);
}

int Stack_peek(const Stack* s) {
    if (Stack_is_empty(s)) {
        fprintf(stderr, "ERROR in 'Stack_peek'\n");
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return List_get_last_val(s->data);
}

int Stack_pop(Stack* s) {
    if (Stack_is_empty(s)) {
        fprintf(stderr, "ERROR in 'Stack_pop'\n");
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    int value = List_get_last_val(s->data);
    List_remove_last(s->data);

    return value;
}

void Stack_print(const Stack* s) {
    List_print(s->data);
}

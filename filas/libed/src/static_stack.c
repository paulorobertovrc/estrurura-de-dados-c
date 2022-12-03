#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

typedef struct _static_stack {
    int* data;
    int capacity;
    int top;
} StaticStack;


StaticStack* StaticStack_create(int capacity) {
    StaticStack* s = (StaticStack*) calloc(1, sizeof(StaticStack));
    
    s->capacity = capacity;
    s->top = -1;
    s->data = (int*) calloc(s->capacity, sizeof(int));

    return s;
}

void StaticStack_destroy(StaticStack** s_ref) {
    StaticStack* s = *s_ref;

    free(s->data);
    free(s);

    *s_ref = NULL;
}

bool StaticStack_is_empty(const StaticStack* s) {
    return s->top == -1;
}

bool StaticStack_is_full(const StaticStack* s) {
    return s->top == (s->capacity - 1);
}

int StaticStack_size(const StaticStack* s) {
    return s->top + 1;
}

void StaticStack_push(StaticStack* s, int value) {
    if (StaticStack_is_full(s)) {
        fprintf(stderr, "ERROR in 'StaticStack_push'\n");
        fprintf(stderr, "The stack is full\n");
        exit(EXIT_FAILURE);
    }
    
    s->top++;
    s->data[s->top] = value;
}

int StaticStack_peek(const StaticStack* s) {
    if (StaticStack_is_empty(s)) {
        fprintf(stderr, "ERROR in 'StaticStack_peek'\n");
        fprintf(stderr, "The stack is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return s->data[s->top];
}

int StaticStack_pop(StaticStack* s) {
    if (StaticStack_is_empty(s)) {
        fprintf(stderr, "ERROR in 'StaticStack_pop'\n");
        fprintf(stderr, "The stack is empty\n");
        exit(EXIT_FAILURE);
    }
    
    int value = s->data[s->top];
    s->top--;

    return value;
}

void StaticStack_print(const StaticStack* s) {  
    printf("Capacity: %d\n", s->capacity);
    printf("Top: %d\n", s->top);

    for (int i = 0; i <= s->top; i++) {
        printf("%d | ", s->data[i]);
    }
    printf("\n");
}

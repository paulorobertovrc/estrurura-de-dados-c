#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _stack Stack;

Stack* Stack_create();
void Stack_destroy(Stack** s_ref);

bool Stack_is_empty(const Stack* s);
size_t Stack_size(const Stack* s);

void Stack_push(Stack* s, int value);
int Stack_peek(const Stack* s);
int Stack_pop(Stack* s);

void Stack_print(const Stack* s);

#endif

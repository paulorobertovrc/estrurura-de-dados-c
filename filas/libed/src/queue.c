#include "queue.h"
#include "linked_list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {
    List* data;
} Queue;

Queue* Queue_create() {
    Queue* q = (Queue*) calloc(1, sizeof(Queue));
    
    q->data = List_create();

    return q;
}

void Queue_destroy(Queue **q_ref) {
    Queue* q = *q_ref;
    
    List_destroy(&q->data);
    free(q);
    
    *q_ref = NULL;
}

bool Queue_is_empty(const Queue *q) {
    return List_is_empty(q->data);
}

long Queue_size(const Queue *q) {
    return List_size(q->data);
}

void Queue_enqueue(Queue *q, int value) {
    List_add_last(q->data, value);
}

int Queue_peek(const Queue *q) {
    if (Queue_is_empty(q)) {
        fprintf(stderr, "ERROR in 'Queue_peek'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return List_get_first_val(q->data);
}

int Queue_dequeue(Queue *q) {
    if (Queue_is_empty(q)) {
        fprintf(stderr, "ERROR in 'Queue_dequeue'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int value = List_get_first_val(q->data);
    List_remove_first(q->data);

    return value;
}

void Queue_print(const Queue *q) {
    List_print(q->data);
}

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"


typedef struct _static_queue {
    int* data;
    int begin;
    int end;
    size_t capacity;
    size_t size;
} StaticQueue;


StaticQueue* StaticQueue_create(size_t capacity) {
    StaticQueue* q = (StaticQueue*) calloc(1, sizeof(StaticQueue));
    
    q->capacity = capacity;
    q->data = (int*) calloc(capacity, sizeof(int));
    q->size = 0;
    q->begin = q->end = 0;

    return q;
}

void StaticQueue_destroy(StaticQueue** q_ref) {
    StaticQueue* q = *q_ref;

    free(q->data);
    free(q);

    *q_ref = NULL;
}

bool StaticQueue_is_empty(const StaticQueue* q) {
    return q->size == 0;
}
bool StaticQueue_is_full(const StaticQueue* q) {
    return q->size == q->capacity;
}

int StaticQueue_size(const StaticQueue* q) {
    return q->size;
}

void StaticQueue_enqueue(StaticQueue* q, int value) {   
    if (StaticQueue_is_full(q)) {
        fprintf(stderr, "ERROR in 'StaticQueue_enqueue'\n");
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }

    q->data[q->end] = value;
    q->end = (q->end + 1) % q->capacity;
    q->size++;
}

int StaticQueue_peek(const StaticQueue* q) {
    if (StaticQueue_is_empty(q)) {
        fprintf(stderr, "ERROR in 'StaticQueue_peek'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return q->data[q->begin];
}

int StaticQueue_dequeue(StaticQueue* q) {
    if (StaticQueue_is_empty(q)) {
        fprintf(stderr, "ERROR in 'StaticQueue_dequeue'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int value = q->data[q->begin];
    q->begin = (q->begin + 1) % q->capacity;
    q->size--;

    return value;
}

void StaticQueue_print(const StaticQueue* q) {
    printf("Capacity: %lu\n", q->capacity);
    printf("Size: %lu\n", q->size);
    printf("Begin: %d\n", q->begin);
    printf("End: %d\n", q->end);

    int s, i;

    for (s = 0, i = q->begin; s < q->size; s++, i = (i + 1) % q->capacity) {
        printf("%d, ", q->data[i]);
    }
    printf("\n");
}
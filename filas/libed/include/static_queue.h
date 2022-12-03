#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _static_queue StaticQueue;

StaticQueue* StaticQueue_create(size_t capacity);
void StaticQueue_destroy(StaticQueue** q_ref);

bool StaticQueue_is_empty(const StaticQueue* q);
bool StaticQueue_is_full(const StaticQueue* q);
int StaticQueue_size(const StaticQueue* q);

void StaticQueue_enqueue(StaticQueue* q, int value);
int StaticQueue_peek(const StaticQueue* q);
int StaticQueue_dequeue(StaticQueue* q);

void StaticQueue_print(const StaticQueue* q);

#endif

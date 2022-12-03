#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct _queue Queue;

Queue *Queue_create();
void Queue_destroy(Queue **q_ref);

bool Queue_is_empty(const Queue *q);
long Queue_size(const Queue *q);

void Queue_enqueue(Queue *q, int value);
int Queue_peek(const Queue *q);
int Queue_dequeue(Queue *q);

void Queue_print(const Queue *q);

#endif

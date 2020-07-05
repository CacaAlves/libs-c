#include <stdbool.h>

typedef struct QueueFloat
{
    float value;
    struct QueueFloat *next;
} QueueFloat;

void enqueue_queue_float(QueueFloat **queue, float value); /*Inserts at the end*/
void dequeue_queue_float(QueueFloat **queue);              /*Removes at the beginning*/
float peek_queue_float(QueueFloat *queue);                 /*Returns the first value*/
bool is_empty_queue_float(QueueFloat *queue);              /*Returns whether the queue is empty or not*/
void print_queue_float(QueueFloat **queue);                /*Prints the queue*/
#include <stdbool.h>

typedef struct QueueFloat
{
    float data;
    struct QueueFloat *next;
} QueueFloat;

void enqueue_queue_float(QueueFloat **queue, float data); /*Inserts at the end*/
void dequeue_queue_float(QueueFloat **queue);             /*Removes at the beginning*/
float peek_queue_float(QueueFloat *queue);                /*Returns the first data*/
bool is_empty_queue_float(QueueFloat *queue);             /*Returns whether the queue is empty or not*/
void print_queue_float(QueueFloat **queue);               /*Prints the queue*/
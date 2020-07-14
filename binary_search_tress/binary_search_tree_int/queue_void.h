#include <stdbool.h>

typedef struct QueueVoid
{
    void *data;
    struct QueueVoid *next;
} QueueVoid;

void enqueue_queue_void(QueueVoid **queue, void *data); /*Inserts at the end*/
void dequeue_queue_void(QueueVoid **queue);             /*Removes at the beginning*/
void *peek_queue_void(QueueVoid *queue);                /*Returns the first data*/
bool is_empty_queue_void(QueueVoid *queue);             /*Returns whether the queue is empty or not*/
void print_queue_void(QueueVoid **queue);               /*Prints the queue*/
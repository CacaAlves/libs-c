#include <stdbool.h>

typedef struct QueueLlu
{
    long long unsigned int value;
    struct QueueLlu *next;
} QueueLlu;

void enqueue_queue_llu(QueueLlu **queue, long long unsigned int value); /*Inserts at the end*/
void dequeue_queue_llu(QueueLlu **queue);                               /*Removes at the beginning*/
long long unsigned int peek_queue_llu(QueueLlu *queue);                 /*Returns the first value*/
bool is_empty_queue_llu(QueueLlu *queue);                               /*Returns whether the queue is empty or not*/
void print_queue_llu(QueueLlu **queue);                                 /*Prints the queue*/
#include <stdbool.h>

typedef struct QueueLld
{
    long long int value;
    struct QueueLld *next;
} QueueLld;

void enqueue_queue_lld(QueueLld **queue, long long int value); /*Inserts at the end*/
void dequeue_queue_lld(QueueLld **queue);                      /*Removes at the beginning*/
long long int peek_queue_lld(QueueLld *queue);                 /*Returns the first value*/
bool is_empty_queue_lld(QueueLld *queue);                      /*Returns whether the queue is empty or not*/
void print_queue_lld(QueueLld **queue);                        /*Prints the queue*/
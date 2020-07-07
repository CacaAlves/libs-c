#include <stdbool.h>

typedef struct QueueLld
{
    long long int data;
    struct QueueLld *next;
} QueueLld;

void enqueue_queue_lld(QueueLld **queue, long long int data); /*Inserts at the end*/
void dequeue_queue_lld(QueueLld **queue);                     /*Removes at the beginning*/
long long int peek_queue_lld(QueueLld *queue);                /*Returns the first data*/
bool is_empty_queue_lld(QueueLld *queue);                     /*Returns whether the queue is empty or not*/
void print_queue_lld(QueueLld **queue);                       /*Prints the queue*/
#include <stdbool.h>

typedef struct QueueInt
{
    int value;
    struct QueueInt *next;
} QueueInt;

void enqueue_queue_int(QueueInt **queue, int value); /*Inserts at the end*/
void dequeue_queue_int(QueueInt **queue);            /*Removes at the beginning*/
int peek_queue_int(QueueInt *queue);                 /*Returns the first value*/
bool is_empty_queue_int(QueueInt *queue);            /*Returns whether the queue is empty or not*/
void print_queue_int(QueueInt **queue);              /*Prints the queue*/
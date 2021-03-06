#include <stdbool.h>

typedef struct QueueDouble
{
    double data;
    struct QueueDouble *next;
} QueueDouble;

void enqueue_queue_double(QueueDouble **queue, double data); /*Inserts at the end*/
void dequeue_queue_double(QueueDouble **queue);              /*Removes at the beginning*/
double peek_queue_double(QueueDouble *queue);                /*Returns the first data*/
bool is_empty_queue_double(QueueDouble *queue);              /*Returns whether the queue is empty or not*/
void print_queue_double(QueueDouble **queue);                /*Prints the queue*/
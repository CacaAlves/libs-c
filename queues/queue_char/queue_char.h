#include <stdbool.h>

typedef struct QueueChar
{
    char value;
    struct QueueChar *next;
} QueueChar;

void enqueue_queue_char(QueueChar **queue, char value); /*Inserts at the end*/
void dequeue_queue_char(QueueChar **queue);             /*Removes at the beginning*/
char peek_queue_char(QueueChar *queue);                 /*Returns the first value*/
bool is_empty_queue_char(QueueChar *queue);             /*Returns whether the queue is empty or not*/
void print_queue_char(QueueChar **queue);               /*Prints the queue*/
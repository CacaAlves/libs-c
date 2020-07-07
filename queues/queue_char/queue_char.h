#include <stdbool.h>

typedef struct QueueChar
{
    char data;
    struct QueueChar *next;
} QueueChar;

void enqueue_queue_char(QueueChar **queue, char data); /*Inserts at the end*/
void dequeue_queue_char(QueueChar **queue);            /*Removes at the beginning*/
char peek_queue_char(QueueChar *queue);                /*Returns the first data*/
bool is_empty_queue_char(QueueChar *queue);            /*Returns whether the queue is empty or not*/
void print_queue_char(QueueChar **queue);              /*Prints the queue*/
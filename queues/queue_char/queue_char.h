#include <stdbool.h>

typedef struct QueueChar
{
    char value;
    struct QueueChar *next;
} QueueChar;

void enqueue_queue_char(QueueChar **queue, char value);
void dequeue_queue_char(QueueChar **queue);
char peek_queue_char(QueueChar *queue);
bool is_empty_queue_char(QueueChar *queue);
void print_queue_char(QueueChar **queue);
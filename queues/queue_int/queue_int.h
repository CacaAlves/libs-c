#include <stdbool.h>

typedef struct QueueInt
{
    int value;
    struct QueueInt *next;
} QueueInt;

void enqueue_queue_int(QueueInt **queue, int value);
void dequeue_queue_int(QueueInt **queue);
int peek_queue_int(QueueInt *queue);
bool is_empty_queue_int(QueueInt *queue);
void print_queue_int(QueueInt **queue);
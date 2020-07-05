#include <stdbool.h>

typedef struct QueueLlu
{
    long long unsigned int value;
    struct QueueLlu *next;
} QueueLlu;

void enqueue_queue_llu(QueueLlu **queue, long long unsigned int value);
void dequeue_queue_llu(QueueLlu **queue);
long long unsigned int peek_queue_llu(QueueLlu *queue);
bool is_empty_queue_llu(QueueLlu *queue);
void print_queue_llu(QueueLlu **queue);
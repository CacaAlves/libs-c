#include <stdbool.h>

typedef struct QueueFloat
{
    float value;
    struct QueueFloat *next;
} QueueFloat;

void enqueue_queue_float(QueueFloat **queue, float value);
void dequeue_queue_float(QueueFloat **queue);
float peek_queue_float(QueueFloat *queue);
bool is_empty_queue_float(QueueFloat *queue);
void print_queue_float(QueueFloat **queue);
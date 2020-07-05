#include <stdbool.h>

typedef struct QueueDouble
{
    double value;
    struct QueueDouble *next;
} QueueDouble;

void enqueue_queue_double(QueueDouble **queue, double value);
void dequeue_queue_double(QueueDouble **queue);
double peek_queue_double(QueueDouble *queue);
bool is_empty_queue_double(QueueDouble *queue);
void print_queue_double(QueueDouble **queue);
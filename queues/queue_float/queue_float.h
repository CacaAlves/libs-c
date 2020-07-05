#include <stdbool.h>

typedef struct Node
{
    float value;
    struct Node *next;
} Node;

void enqueue_queue_float(Node **queue, float value);
void dequeue_queue_float(Node **queue);
float peek_queue_float(Node *queue);
bool is_empty_queue_float(Node *queue);
void print_queue_float(Node **queue);
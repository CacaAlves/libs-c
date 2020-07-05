#include <stdbool.h>

typedef struct Node
{
    double value;
    struct Node *next;
} Node;

void enqueue_queue_double(Node **queue, double value);
void dequeue_queue_double(Node **queue);
double peek_queue_double(Node *queue);
bool is_empty_queue_double(Node *queue);
void print_queue_double(Node **queue);
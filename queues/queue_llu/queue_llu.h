#include <stdbool.h>

typedef struct Node
{
    long long unsigned int value;
    struct Node *next;
} Node;

void enqueue_queue_llu(Node **queue, long long unsigned int value);
void dequeue_queue_llu(Node **queue);
long long unsigned int peek_queue_llu(Node *queue);
bool is_empty_queue_llu(Node *queue);
void print_queue_llu(Node **queue);
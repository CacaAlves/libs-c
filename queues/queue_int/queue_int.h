#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void enqueue_queue_int(Node **queue, int value);
void dequeue_queue_int(Node **queue);
int peek_queue_int(Node *queue);
bool is_empty_queue_int(Node *queue);
void print_queue_int(Node **queue);
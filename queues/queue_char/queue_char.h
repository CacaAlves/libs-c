#include <stdbool.h>

typedef struct Node
{
    char value;
    struct Node *next;
} Node;

void enqueue_queue_char(Node **queue, char value);
void dequeue_queue_char(Node **queue);
char peek_queue_char(Node *queue);
bool is_empty_queue_char(Node *queue);
void print_queue_char(Node **queue);
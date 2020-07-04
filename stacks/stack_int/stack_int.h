#include <stdbool.h>

typedef struct Node {
    char value;
    struct Node *next;
}Node;

void push_stack_int(Node **stack, int value);
int top_stack_int(Node *stack);
void pop_stack_int(Node **stack);
void print_stack_int(Node **stack);
bool is_empty_stack_int(Node *stack);
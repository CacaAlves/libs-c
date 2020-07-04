#include <stdbool.h>

typedef struct Node {
    long long unsigned int value;
    struct Node *next;
}Node;

void push_stack_llu(Node **stack, long long unsigned int value);
long long unsigned int top_stack_llu(Node *stack);
void pop_stack_llu(Node **stack);
void print_stack_llu(Node **stack);
bool is_empty_stack_llu(Node *stack);
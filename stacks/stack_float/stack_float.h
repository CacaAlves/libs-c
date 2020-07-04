#include <stdbool.h>

typedef struct Node {
    float value;
    struct Node *next;
}Node;

void push_stack_float(Node **stack, float value);
float top_stack_float(Node *stack);
void pop_stack_float(Node **stack);
void print_stack_float(Node **stack);
bool is_empty_stack_float(Node *stack);
#include <stdbool.h>

typedef struct Node {
    double value;
    struct Node *next;
}Node;

void push_stack_double(Node **stack, double value);
double top_stack_double(Node *stack);
void pop_stack_double(Node **stack);
void print_stack_double(Node **stack);
bool is_empty_stack_double(Node *stack);
#include <stdbool.h>

typedef struct Node
{
    char value;
    struct Node *next;
} Node;

void push_stack_char(Node **stack, char value);
char top_stack_char(Node *stack);
void pop_stack_char(Node **stack);
void print_stack_char(Node **stack);
bool is_empty_stack_char(Node *stack);
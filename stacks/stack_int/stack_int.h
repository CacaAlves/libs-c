#include <stdbool.h>

typedef struct StackInt
{
    int value;
    struct StackInt *next;
} StackInt;

void push_stack_int(StackInt **stack, int value);
int top_stack_int(StackInt *stack);
void pop_stack_int(StackInt **stack);
void print_stack_int(StackInt **stack);
bool is_empty_stack_int(StackInt *stack);
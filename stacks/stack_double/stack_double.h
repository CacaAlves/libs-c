#include <stdbool.h>

typedef struct StackDouble
{
    double value;
    struct StackDouble *next;
} StackDouble;

void push_stack_double(StackDouble **stack, double value);
double top_stack_double(StackDouble *stack);
void pop_stack_double(StackDouble **stack);
void print_stack_double(StackDouble **stack);
bool is_empty_stack_double(StackDouble *stack);
#include <stdbool.h>

typedef struct StackFloat
{
    float value;
    struct StackFloat *next;
} StackFloat;

void push_stack_float(StackFloat **stack, float value);
float top_stack_float(StackFloat *stack);
void pop_stack_float(StackFloat **stack);
void print_stack_float(StackFloat **stack);
bool is_empty_stack_float(StackFloat *stack);
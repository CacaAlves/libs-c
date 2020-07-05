#include <stdbool.h>

typedef struct StackFloat
{
    float value;
    struct StackFloat *next;
} StackFloat;

void push_stack_float(StackFloat **stack, float value); /*Inserts at the end*/
float top_stack_float(StackFloat *stack);               /*Returns the last value*/
void pop_stack_float(StackFloat **stack);               /*Removes at the end*/
void print_stack_float(StackFloat **stack);             /*Prints the stack*/
bool is_empty_stack_float(StackFloat *stack);           /*Returns whether the stack is empty or not*/
#include <stdbool.h>

typedef struct StackDouble
{
    double data;
    struct StackDouble *next;
} StackDouble;

void push_stack_double(StackDouble **stack, double data); /*Inserts at the end*/
double top_stack_double(StackDouble *stack);              /*Returns the last data*/
void pop_stack_double(StackDouble **stack);               /*Removes at the end*/
void print_stack_double(StackDouble **stack);             /*Prints the stack*/
bool is_empty_stack_double(StackDouble *stack);           /*Returns whether the stack is empty or not*/
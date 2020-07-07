#include <stdbool.h>

typedef struct StackFloat
{
    float data;
    struct StackFloat *next;
} StackFloat;

void push_stack_float(StackFloat **stack, float data); /*Inserts at the end*/
float top_stack_float(StackFloat *stack);              /*Returns the last data*/
void pop_stack_float(StackFloat **stack);              /*Removes at the end*/
void print_stack_float(StackFloat **stack);            /*Prints the stack*/
bool is_empty_stack_float(StackFloat *stack);          /*Returns whether the stack is empty or not*/
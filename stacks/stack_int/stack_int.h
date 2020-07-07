#include <stdbool.h>

typedef struct StackInt
{
    int data;
    struct StackInt *next;
} StackInt;

void push_stack_int(StackInt **stack, int data); /*Inserts at the end*/
int top_stack_int(StackInt *stack);              /*Returns the last data*/
void pop_stack_int(StackInt **stack);            /*Removes at the end*/
void print_stack_int(StackInt **stack);          /*Prints the stack*/
bool is_empty_stack_int(StackInt *stack);        /*Returns whether the stack is empty or not*/
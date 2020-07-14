#include <stdbool.h>

typedef struct StackVoid
{
    void *data;
    struct StackVoid *next;
} StackVoid;

void push_stack_void(StackVoid **stack, void *data); /*Inserts at the end*/
void *top_stack_void(StackVoid *stack);              /*Returns the last data*/
void pop_stack_void(StackVoid **stack);              /*Removes at the end*/
void print_stack_void(StackVoid **stack);            /*Prints the stack*/
bool is_empty_stack_void(StackVoid *stack);          /*Returns whether the stack is empty or not*/
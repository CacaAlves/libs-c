#include <stdbool.h>

typedef struct StackLlu
{
    long long unsigned int data;
    struct StackLlu *next;
} StackLlu;

void push_stack_llu(StackLlu **stack, long long unsigned int data); /*Inserts at the end*/
long long unsigned int top_stack_llu(StackLlu *stack);              /*Returns the last data*/
void pop_stack_llu(StackLlu **stack);                               /*Removes at the end*/
void print_stack_llu(StackLlu **stack);                             /*Prints the stack*/
bool is_empty_stack_llu(StackLlu *stack);                           /*Returns whether the stack is empty or not*/
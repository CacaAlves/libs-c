#include <stdbool.h>

typedef struct StackLld
{
    long long int value;
    struct StackLld *next;
} StackLld;

void push_stack_lld(StackLld **stack, long long int value); /*Inserts at the end*/
long long int top_stack_lld(StackLld *stack);               /*Returns the last value*/
void pop_stack_lld(StackLld **stack);                       /*Removes at the end*/
void print_stack_lld(StackLld **stack);                     /*Prints the stack*/
bool is_empty_stack_lld(StackLld *stack);                   /*Returns whether the stack is empty or not*/
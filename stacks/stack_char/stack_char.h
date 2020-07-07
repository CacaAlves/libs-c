#include <stdbool.h>

typedef struct StackChar
{
    char data;
    struct StackChar *next;
} StackChar;

void push_stack_char(StackChar **stack, char data); /*Inserts at the end*/
char top_stack_char(StackChar *stack);              /*Returns the last data*/
void pop_stack_char(StackChar **stack);             /*Removes at the end*/
void print_stack_char(StackChar **stack);           /*Prints the stack*/
bool is_empty_stack_char(StackChar *stack);         /*Returns whether the stack is empty or not*/
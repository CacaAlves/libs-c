#include <stdbool.h>

typedef struct StackChar
{
    char value;
    struct StackChar *next;
} StackChar;

void push_stack_char(StackChar **stack, char value);
char top_stack_char(StackChar *stack);
void pop_stack_char(StackChar **stack);
void print_stack_char(StackChar **stack);
bool is_empty_stack_char(StackChar *stack);
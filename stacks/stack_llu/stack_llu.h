#include <stdbool.h>

typedef struct StackLlu
{
    long long unsigned int value;
    struct StackLlu *next;
} StackLlu;

void push_stack_llu(StackLlu **stack, long long unsigned int value);
long long unsigned int top_stack_llu(StackLlu *stack);
void pop_stack_llu(StackLlu **stack);
void print_stack_llu(StackLlu **stack);
bool is_empty_stack_llu(StackLlu *stack);
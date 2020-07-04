#include <stdio.h>
#include "stack_llu.h"

void main() {
    Node *stack = NULL;
    push_stack_llu(&stack, 10000000);
    push_stack_llu(&stack, 20000000);
    push_stack_llu(&stack, 30000000);
    push_stack_llu(&stack, 40000000);
    push_stack_llu(&stack, 50000000);
    printf("%llu\n", top_stack_llu(stack));
    pop_stack_llu(&stack);
    printf("Is empty: %d\n", is_empty_stack_llu(stack));
    print_stack_llu(&stack);
    printf("Is empty: %d\n", is_empty_stack_llu(stack));
}
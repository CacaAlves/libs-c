#include <stdio.h>
#include "stack_int.h"

void main() {
    Node *stack = NULL;
    push_stack_int(&stack, 100);
    push_stack_int(&stack, 200);
    push_stack_int(&stack, 300);
    push_stack_int(&stack, 400);
    push_stack_int(&stack, 500);
    printf("%d\n", top_stack_int(stack));
    pop_stack_int(&stack);
    printf("Is empty: %d\n", is_empty_stack_int(stack));
    print_stack_int(&stack);
    printf("Is empty: %d\n", is_empty_stack_int(stack));
}
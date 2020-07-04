#include <stdio.h>
#include "stack_char.h"

void main() {
    Node *stack = NULL;
    push_stack_char(&stack, 'a');
    push_stack_char(&stack, 'b');
    push_stack_char(&stack, 'c');
    push_stack_char(&stack, 'd');
    push_stack_char(&stack, 'e');
    printf("%c\n", top_stack_char(stack));
    pop_stack_char(&stack);
    printf("Is empty: %d\n", is_empty_stack_char(stack));
    print_stack_char(&stack);
    printf("Is empty: %d\n", is_empty_stack_char(stack));
}
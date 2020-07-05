#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_char.h"

StackChar *new_node_stack_char(char value)
{
    StackChar *node = (StackChar *)malloc(sizeof(StackChar));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_stack_char(StackChar **stack, char value)
{
    if (stack == NULL)
        return;

    StackChar *node = new_node_stack_char(value);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackChar *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

char top_stack_char(StackChar *stack)
{
    if (stack != NULL)
    {
        return stack->value;
    }
}

void pop_stack_char(StackChar **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    StackChar *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_char(StackChar *stack)
{
    return (stack == NULL);
}

void print_stack_char(StackChar **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    while ((*stack) != NULL)
    {
        printf("%c", top_stack_char(*stack));
        pop_stack_char(stack);
    }
    printf("\n");
}
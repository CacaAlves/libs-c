#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_lld.h"

StackLld *new_node_stack_lld(long long int value)
{
    StackLld *node = (StackLld *)malloc(sizeof(StackLld));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_stack_lld(StackLld **stack, long long int value)
{
    if (stack == NULL)
        return;

    StackLld *node = new_node_stack_lld(value);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackLld *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

long long int top_stack_lld(StackLld *stack)
{
    if (stack != NULL)
    {
        return stack->value;
    }
}

void pop_stack_lld(StackLld **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    StackLld *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_lld(StackLld *stack)
{
    return (stack == NULL);
}

void print_stack_lld(StackLld **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    while ((*stack) != NULL)
    {
        printf("%lld ", top_stack_lld(*stack));
        pop_stack_lld(stack);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_int.h"

StackInt *new_node_stack_int(int value)
{
    StackInt *node = (StackInt *)malloc(sizeof(StackInt));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_stack_int(StackInt **stack, int value)
{
    if (stack == NULL)
        return;

    StackInt *node = new_node_stack_int(value);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackInt *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

int top_stack_int(StackInt *stack)
{
    if (stack != NULL)
    {
        return stack->value;
    }
}

void pop_stack_int(StackInt **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    StackInt *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_int(StackInt *stack)
{
    return (stack == NULL);
}

void print_stack_int(StackInt **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    while ((*stack) != NULL)
    {
        printf("%d ", top_stack_int(*stack));
        pop_stack_int(stack);
    }
    printf("\n");
}
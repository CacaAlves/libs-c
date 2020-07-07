#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_double.h"

StackDouble *new_node_stack_double(double data)
{
    StackDouble *node = (StackDouble *)malloc(sizeof(StackDouble));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_stack_double(StackDouble **stack, double data)
{
    if (stack == NULL)
        return;

    StackDouble *node = new_node_stack_double(data);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackDouble *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

double top_stack_double(StackDouble *stack)
{
    if (stack != NULL)
    {
        return stack->data;
    }
}

void pop_stack_double(StackDouble **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    StackDouble *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_double(StackDouble *stack)
{
    return (stack == NULL);
}

void print_stack_double(StackDouble **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    while ((*stack) != NULL)
    {
        printf("%f ", top_stack_double(*stack));
        pop_stack_double(stack);
    }
    printf("\n");
}
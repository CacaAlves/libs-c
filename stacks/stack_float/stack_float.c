#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_float.h"

StackFloat *new_node_stack_float(float value)
{
    StackFloat *node = (StackFloat *)malloc(sizeof(StackFloat));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_stack_float(StackFloat **stack, float value)
{
    if (stack == NULL)
        return;

    StackFloat *node = new_node_stack_float(value);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackFloat *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

float top_stack_float(StackFloat *stack)
{
    if (stack != NULL)
    {
        return stack->value;
    }
}

void pop_stack_float(StackFloat **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    StackFloat *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_float(StackFloat *stack)
{
    return (stack == NULL);
}

void print_stack_float(StackFloat **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    while ((*stack) != NULL)
    {
        printf("%f ", top_stack_float(*stack));
        pop_stack_float(stack);
    }
    printf("\n");
}
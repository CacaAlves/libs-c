#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_double.h"

Node *new_node_stack_double(double value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_stack_double(Node **stack, double value)
{
    if (stack == NULL)
        return;

    Node *node = new_node_stack_double(value);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        Node *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

double top_stack_double(Node *stack)
{
    if (stack != NULL)
    {
        return stack->value;
    }
}

void pop_stack_double(Node **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    Node *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_double(Node *stack)
{
    return (stack == NULL);
}

void print_stack_double(Node **stack)
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
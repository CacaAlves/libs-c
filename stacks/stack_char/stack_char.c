#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_char.h"

Node *new_node_stack_char(char value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_stack_char(Node **stack, char value)
{
    if (stack == NULL)
        return;

    Node *node = new_node_stack_char(value);

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

char top_stack_char(Node *stack)
{
    if (stack != NULL)
    {
        return stack->value;
    }
}

void pop_stack_char(Node **stack)
{
    if (stack == NULL || (*stack) == NULL)
        return;

    Node *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_char(Node *stack)
{
    return (stack == NULL);
}

void print_stack_char(Node **stack)
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
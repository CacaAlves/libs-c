#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_char.h"

StackChar *new_node_stack_char(char data)
{
    StackChar *node = (StackChar *)malloc(sizeof(StackChar));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_stack_char(StackChar **stack, char data)
{
    if (stack == NULL)
        return;

    StackChar *node = new_node_stack_char(data);

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
    if (stack == NULL) 
    {
       printf("Can't return top! Stack is empty.\n"); 
    }
    else
    {
        return stack->data;
    }
}

void pop_stack_char(StackChar **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't pop! Empty stack.\n");
        return;
    }

    StackChar *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_char(StackChar *stack)
{
    return (stack == NULL);
}
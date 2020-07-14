#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_void.h"

StackVoid *new_node_stack_void(int *data)
{
    StackVoid *node = (StackVoid *)malloc(sizeof(StackVoid));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_stack_void(StackVoid **stack, void *data)
{
    if (stack == NULL)
        return;

    StackVoid *node = new_node_stack_void(data);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackVoid *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

void *top_stack_void(StackVoid *stack)
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

void pop_stack_void(StackVoid **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't pop! Empty stack.\n");
        return;
    }

    StackVoid *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_void(StackVoid *stack)
{
    return (stack == NULL);
}

void print_stack_void(StackVoid **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't print! Empty stack.\n");
        return;
    }

    while ((*stack) != NULL)
    {
        printf("%p ", top_stack_void(*stack));
        pop_stack_void(stack);
    }
    printf("\n");
}
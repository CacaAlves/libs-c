#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_llu.h"

StackLlu *new_node_stack_llu(long long unsigned int data)
{
    StackLlu *node = (StackLlu *)malloc(sizeof(StackLlu));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_stack_llu(StackLlu **stack, long long unsigned int data)
{
    if (stack == NULL)
        return;

    StackLlu *node = new_node_stack_llu(data);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackLlu *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

long long unsigned int top_stack_llu(StackLlu *stack)
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

void pop_stack_llu(StackLlu **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't pop! Empty stack.\n");
        return;
    }

    StackLlu *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_llu(StackLlu *stack)
{
    return (stack == NULL);
}

void print_stack_llu(StackLlu **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't print! Empty stack.\n");
        return;
    }

    while ((*stack) != NULL)
    {
        printf("%llu ", top_stack_llu(*stack));
        pop_stack_llu(stack);
    }
    printf("\n");
}
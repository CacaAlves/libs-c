#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_llu.h"

Node *new_node_stack_llu(long long unsigned int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    
    return node;
}

void push_stack_llu(Node **stack, long long unsigned int value) {
    if (stack == NULL) return;

    Node *node = new_node_stack_llu(value);

    if ((*stack) == NULL) {
        (*stack) = node;
    }
    else {
        Node *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

long long unsigned int top_stack_llu(Node *stack) {
    if (stack != NULL) {
        return stack->value;
    }
}

void pop_stack_llu(Node **stack) {
    if (stack == NULL || (*stack) == NULL) return;

    Node *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_llu(Node *stack) {
    return (stack == NULL);
}

void print_stack_llu(Node **stack) {
    if (stack == NULL || (*stack) == NULL) return;

    while ((*stack) != NULL) {
        printf("%llu ", top_stack_llu(*stack));
        pop_stack_llu(stack);
    }
    printf("\n");
}
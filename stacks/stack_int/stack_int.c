#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_int.h"

Node *new_node_stack_int(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    
    return node;
}

void push_stack_int(Node **stack, int value) {
    if (stack == NULL) return;

    Node *node = new_node_stack_int(value);

    if ((*stack) == NULL) {
        (*stack) = node;
    }
    else {
        Node *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

int top_stack_int(Node *stack) {
    if (stack != NULL) {
        return stack->value;
    }
}

void pop_stack_int(Node **stack) {
    if (stack == NULL || (*stack) == NULL) return;

    Node *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_int(Node *stack) {
    return (stack == NULL);
}

void print_stack_int(Node **stack) {
    if (stack == NULL || (*stack) == NULL) return;

    while ((*stack) != NULL) {
        printf("%d ", top_stack_int(*stack));
        pop_stack_int(stack);
    }
    printf("\n");
}
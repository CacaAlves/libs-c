#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_float.h"

Node *new_node_stack_float(float value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    
    return node;
}

void push_stack_float(Node **stack, float value) {
    if (stack == NULL) return;

    Node *node = new_node_stack_float(value);

    if ((*stack) == NULL) {
        (*stack) = node;
    }
    else {
        Node *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

float top_stack_float(Node *stack) {
    if (stack != NULL) {
        return stack->value;
    }
}

void pop_stack_float(Node **stack) {
    if (stack == NULL || (*stack) == NULL) return;

    Node *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_float(Node *stack) {
    return (stack == NULL);
}

void print_stack_float(Node **stack) {
    if (stack == NULL || (*stack) == NULL) return;

    while ((*stack) != NULL) {
        printf("%f ", top_stack_float(*stack));
        pop_stack_float(stack);
    }
    printf("\n");
}
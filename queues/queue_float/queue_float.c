#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_float.h"

Node *new_node_queue_float(float value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue_queue_float(Node **queue, float value)
{
    if ((queue) == NULL)
        return;

    Node *node = new_node_queue_float(value);

    if ((*queue) == NULL)
    {
        (*queue) = (Node *)malloc(sizeof(Node));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        Node *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_float(Node **queue)
{
    if ((queue) == NULL || (*queue) == NULL)
        return;

    if ((*queue)->next == NULL)
    {
        free((*queue));
        (*queue) = NULL;
    }
    else
    {
        Node *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

float peek_queue_float(Node *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->value);
    }
}

bool is_empty_queue_float(Node *queue)
{
    return (queue == NULL);
}

void print_queue_float(Node **queue)
{
    Node *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%f ", peek_queue_float(*queue));
        aux = aux->next;
        dequeue_queue_float(queue);
    }
    printf("%f\n", peek_queue_float((*queue)));
    dequeue_queue_float(queue);
}
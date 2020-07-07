#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_float.h"

QueueFloat *new_node_queue_float(float data)
{
    QueueFloat *node = (QueueFloat *)malloc(sizeof(QueueFloat));
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue_queue_float(QueueFloat **queue, float data)
{
    if ((queue) == NULL)
        return;

    QueueFloat *node = new_node_queue_float(data);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueFloat *)malloc(sizeof(QueueFloat));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueFloat *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_float(QueueFloat **queue)
{
    if ((queue) == NULL || (*queue) == NULL)
        return;

    if ((*queue)->next == (*queue))
    {
        free((*queue));
        (*queue) = NULL;
    }
    else
    {
        QueueFloat *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

float peek_queue_float(QueueFloat *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->data);
    }
}

bool is_empty_queue_float(QueueFloat *queue)
{
    return (queue == NULL);
}

void print_queue_float(QueueFloat **queue)
{
    QueueFloat *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%f ", peek_queue_float(*queue));
        aux = aux->next;
        dequeue_queue_float(queue);
    }
    printf("%f\n", peek_queue_float((*queue)));
    dequeue_queue_float(queue);
}
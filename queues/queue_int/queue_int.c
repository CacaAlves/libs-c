#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_int.h"

QueueInt *new_node_queue_int(int data)
{
    QueueInt *node = (QueueInt *)malloc(sizeof(QueueInt));
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue_queue_int(QueueInt **queue, int data)
{
    if ((queue) == NULL)
        return;

    QueueInt *node = new_node_queue_int(data);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueInt *)malloc(sizeof(QueueInt));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueInt *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_int(QueueInt **queue)
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
        QueueInt *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

int peek_queue_int(QueueInt *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->data);
    }
}

bool is_empty_queue_int(QueueInt *queue)
{
    return (queue == NULL);
}

void print_queue_int(QueueInt **queue)
{
    QueueInt *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%d ", peek_queue_int(*queue));
        aux = aux->next;
        dequeue_queue_int(queue);
    }
    printf("%d\n", peek_queue_int((*queue)));
    dequeue_queue_int(queue);
}
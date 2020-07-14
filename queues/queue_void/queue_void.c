#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_void.h"

QueueVoid *new_node_queue_void(void *data)
{
    QueueVoid *node = (QueueVoid *)malloc(sizeof(QueueVoid));
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue_queue_void(QueueVoid **queue, void *data)
{
    if ((queue) == NULL)
        return;

    QueueVoid *node = new_node_queue_void(data);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueVoid *)malloc(sizeof(QueueVoid));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueVoid *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_void(QueueVoid **queue)
{
    if ((queue) == NULL || (*queue) == NULL)
    {
        printf("Can't dequeue! Queue is empty.\n");
        return;
    }

    if ((*queue)->next == (*queue))
    {
        free((*queue));
        (*queue) = NULL;
    }
    else
    {
        QueueVoid *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

void *peek_queue_void(QueueVoid *queue)
{
    if (queue == NULL)
    {
        printf("Can't peek queue! Queue is empty.\n");
    }
    else
    {
        return ((queue->next)->data);
    }
}

bool is_empty_queue_void(QueueVoid *queue)
{
    return (queue == NULL);
}

void print_queue_void(QueueVoid **queue)
{
    if (queue == NULL || (*queue) == NULL) 
    {
        printf("Can't print queue! Queue is empty.\n");
        return;
    }

    QueueVoid *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%p ", peek_queue_void(*queue));
        aux = aux->next;
        dequeue_queue_void(queue);
    }
    printf("%p\n", peek_queue_void((*queue)));
    dequeue_queue_void(queue);
}
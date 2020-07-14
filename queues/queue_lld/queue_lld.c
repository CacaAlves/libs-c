#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_lld.h"

QueueLld *new_node_queue_lld(long long int data)
{
    QueueLld *node = (QueueLld *)malloc(sizeof(QueueLld));
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue_queue_lld(QueueLld **queue, long long int data)
{
    if ((queue) == NULL)
        return;

    QueueLld *node = new_node_queue_lld(data);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueLld *)malloc(sizeof(QueueLld));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueLld *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_lld(QueueLld **queue)
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
        QueueLld *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

long long int peek_queue_lld(QueueLld *queue)
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

bool is_empty_queue_lld(QueueLld *queue)
{
    return (queue == NULL);
}

void print_queue_lld(QueueLld **queue)
{
    if (queue == NULL || (*queue) == NULL) 
    {
        printf("Can't print queue! Queue is empty.\n");
        return;
    }

    QueueLld *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%lld ", peek_queue_lld(*queue));
        aux = aux->next;
        dequeue_queue_lld(queue);
    }
    printf("%lld\n", peek_queue_lld((*queue)));
    dequeue_queue_lld(queue);
}
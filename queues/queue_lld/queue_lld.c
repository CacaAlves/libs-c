#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_lld.h"

QueueLld *new_node_queue_lld(long long int value)
{
    QueueLld *node = (QueueLld *)malloc(sizeof(QueueLld));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue_queue_lld(QueueLld **queue, long long int value)
{
    if ((queue) == NULL)
        return;

    QueueLld *node = new_node_queue_lld(value);

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
        return;

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
    if (queue != NULL)
    {
        return ((queue->next)->value);
    }
}

bool is_empty_queue_lld(QueueLld *queue)
{
    return (queue == NULL);
}

void print_queue_lld(QueueLld **queue)
{
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
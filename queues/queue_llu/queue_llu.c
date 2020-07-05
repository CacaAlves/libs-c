#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_llu.h"

QueueLlu *new_node_queue_llu(long long unsigned int value)
{
    QueueLlu *node = (QueueLlu *)malloc(sizeof(QueueLlu));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue_queue_llu(QueueLlu **queue, long long unsigned int value)
{
    if ((queue) == NULL)
        return;

    QueueLlu *node = new_node_queue_llu(value);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueLlu *)malloc(sizeof(QueueLlu));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueLlu *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_llu(QueueLlu **queue)
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
        QueueLlu *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

long long unsigned int peek_queue_llu(QueueLlu *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->value);
    }
}

bool is_empty_queue_llu(QueueLlu *queue)
{
    return (queue == NULL);
}

void print_queue_llu(QueueLlu **queue)
{
    QueueLlu *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%llu ", peek_queue_llu(*queue));
        aux = aux->next;
        dequeue_queue_llu(queue);
    }
    printf("%llu\n", peek_queue_llu((*queue)));
    dequeue_queue_llu(queue);
}
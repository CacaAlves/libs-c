#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue_char.h"

QueueChar *new_node_queue_char(char value)
{
    QueueChar *node = (QueueChar *)malloc(sizeof(QueueChar));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue_queue_char(QueueChar **queue, char value)
{
    if ((queue) == NULL)
        return;

    QueueChar *node = new_node_queue_char(value);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueChar *)malloc(sizeof(QueueChar));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueChar *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_char(QueueChar **queue)
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
        QueueChar *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

char peek_queue_char(QueueChar *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->value);
    }
}

bool is_empty_queue_char(QueueChar *queue)
{
    return (queue == NULL);
}

void print_queue_char(QueueChar **queue)
{
    QueueChar *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%c", peek_queue_char(*queue));
        aux = aux->next;
        dequeue_queue_char(queue);
    }
    printf("%c\n", peek_queue_char((*queue)));
    dequeue_queue_char(queue);
}
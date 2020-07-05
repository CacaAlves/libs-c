#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_llu.h"

Node *new_node_queue_llu(long long unsigned int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue_queue_llu(Node **queue, long long unsigned int value)
{
    if ((queue) == NULL)
        return;

    Node *node = new_node_queue_llu(value);

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

void dequeue_queue_llu(Node **queue)
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

long long unsigned int peek_queue_llu(Node *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->value);
    }
}

bool is_empty_queue_llu(Node *queue)
{
    return (queue == NULL);
}

void print_queue_llu(Node **queue)
{
    Node *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%llu ", peek_queue_llu(*queue));
        aux = aux->next;
        dequeue_queue_llu(queue);
    }
    printf("%llu\n", peek_queue_llu((*queue)));
    dequeue_queue_llu(queue);
}
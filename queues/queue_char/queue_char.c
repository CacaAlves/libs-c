#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue_char.h"

Node *new_node_queue_char(char value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue_queue_char(Node **queue, char value)
{
    if ((queue) == NULL)
        return;

    Node *node = new_node_queue_char(value);

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

void dequeue_queue_char(Node **queue)
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

char peek_queue_char(Node *queue)
{
    if (queue != NULL)
    {
        return ((queue->next)->value);
    }
}

bool is_empty_queue_char(Node *queue)
{
    return (queue == NULL);
}

void print_queue_char(Node **queue)
{
    Node *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%c", peek_queue_char(*queue));
        aux = aux->next;
        dequeue_queue_char(queue);
    }
    printf("%c\n", peek_queue_char((*queue)));
    dequeue_queue_char(queue);
}
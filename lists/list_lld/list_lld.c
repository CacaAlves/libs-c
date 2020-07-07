#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_lld.h"

ListLld *new_node_list_lld(long long int data)
{
    ListLld *node = (ListLld *)malloc(sizeof(ListLld));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_list_lld(ListLld **list, long long int data)
{
    if (list == NULL)
        return;

    ListLld *node = new_node_list_lld(data);

    if ((*list) == NULL)
    {
        (*list) = node;
        (*list)->next = node;
    }
    else
    {
        ListLld *last = (*list);
        node->next = last->next;
        last->next = node;
        (*list) = node;
    }
}

void unshift_list_lld(ListLld **list, long long int data)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_lld(list, data);
    }
    else
    {
        ListLld *node = new_node_list_lld(data);
        ListLld *first = (*list)->next;
        ListLld *last = (*list);
        last->next = node;
        node->next = first;
    }
}

void pop_list_lld(ListLld **list)
{
    if (list == NULL || (*list) == NULL)
        return;

    if ((*list)->next == (*list))
    {
        free(*list);
        (*list) = NULL;
    }
    else
    {
        ListLld *aux = (*list)->next;
        while (aux->next != (*list))
        {
            aux = aux->next;
        }

        aux->next = (*list)->next;
        free(*list);
        (*list) = aux;
    }
}

void shift_list_lld(ListLld **list)
{
    if (list == NULL || (*list) == NULL)
        return;

    if ((*list)->next == (*list))
    {
        free(*list);
        (*list) = NULL;
    }
    else
    {
        ListLld *first = (*list)->next;
        (*list)->next = first->next;
        free(first);
        first = NULL;
    }
}

long long int peek_list_lld(ListLld *list)
{
    if (list != NULL)
    {
        return ((list->next)->data);
    }
}

long long int top_list_lld(ListLld *list)
{
    if (list != NULL)
    {
        return (list->data);
    }
}

long long int index_of_list_lld(ListLld *list, long long int data)
{
    if (list == NULL)
        return -1;

    ListLld *aux = list->next;
    long long int index = 0;

    while (aux != list && aux->data != data)
    {
        aux = aux->next;
        index++;
    }

    return ((aux->data == data) ? index : -1);
}

ListLld *includes_list_lld(ListLld *list, long long int index)
{
    if (list == NULL || index < 0)
        return NULL;

    ListLld *aux = list->next;
    long long int indexCounter = 0;

    while (aux != list && indexCounter != index)
    {
        aux = aux->next;
        indexCounter++;
    }
    return ((indexCounter == index) ? aux : NULL);
}

void delete_list_lld(ListLld **list, long long int index)
{
    if (list == NULL || (*list) == NULL || index < 0)
        return;

    long long int length = length_list_lld((*list));

    if (index >= length)
        return;

    if (index == 0)
    {
        shift_list_lld(list);
        return;
    }
    else if (index == length - 1)
    {
        pop_list_lld(list);
    }
    else
    {
        long long int indexCounter = 0;
        ListLld *aux = (*list)->next;
        while (indexCounter != index - 1) {
            aux = aux->next;
            indexCounter++;
        }

        if (indexCounter == index - 1) {
            ListLld *nodeToDelete = aux->next;
            aux->next = nodeToDelete->next;
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}

void free_list_lld(ListLld **list)
{
    if (list == NULL)
        return;

    ListLld *aux = (*list)->next;
    while (aux != (*list))
    {
        ListLld *prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(aux);
    (*list) = NULL;
}

long long unsigned int length_list_lld(ListLld *list)
{
    if (list == NULL)
        return 0;

    long long unsigned int counter = 0;
    ListLld *aux = list->next;

    while (aux != list)
    {
        counter++;
        aux = aux->next;
    }
    counter++;

    return counter;
}

bool is_empty_list_lld(ListLld *list)
{
    return (list == NULL);
}

void print_list_lld(ListLld *list)
{
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    ListLld *first = list->next;

    while (first != list)
    {
        printf("%lld ", first->data);
        first = first->next;
    }

    printf("%lld\n", list->data);
}

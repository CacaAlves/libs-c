#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_llu.h"

ListLlu *new_node_list_llu(long long unsigned int value)
{
    ListLlu *node = (ListLlu *)malloc(sizeof(ListLlu));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_list_llu(ListLlu **list, long long unsigned int value)
{
    if (list == NULL)
        return;

    ListLlu *node = new_node_list_llu(value);

    if ((*list) == NULL)
    {
        (*list) = node;
        (*list)->next = node;
    }
    else
    {
        ListLlu *last = (*list);
        node->next = last->next;
        last->next = node;
        (*list) = node;
    }
}

void unshift_list_llu(ListLlu **list, long long unsigned int value)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_llu(list, value);
    }
    else
    {
        ListLlu *node = new_node_list_llu(value);
        ListLlu *first = (*list)->next;
        ListLlu *last = (*list);
        last->next = node;
        node->next = first;
    }
}

void pop_list_llu(ListLlu **list)
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
        ListLlu *aux = (*list)->next;
        while (aux->next != (*list))
        {
            aux = aux->next;
        }

        aux->next = (*list)->next;
        free(*list);
        (*list) = aux;
    }
}

void shift_list_llu(ListLlu **list)
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
        ListLlu *first = (*list)->next;
        (*list)->next = first->next;
        free(first);
        first = NULL;
    }
}

long long unsigned int peek_list_llu(ListLlu *list)
{
    if (list != NULL)
    {
        return ((list->next)->value);
    }
}

long long unsigned int top_list_llu(ListLlu *list)
{
    if (list != NULL)
    {
        return (list->value);
    }
}

long long int index_of_list_llu(ListLlu *list, long long unsigned int value)
{
    if (list == NULL)
        return -1;

    ListLlu *aux = list->next;
    long long int index = 0;

    while (aux != list && aux->value != value)
    {
        aux = aux->next;
        index++;
    }

    return ((aux->value == value) ? index : -1);
}

ListLlu *includes_list_llu(ListLlu *list, long long int index)
{
    if (list == NULL || index < 0)
        return NULL;

    ListLlu *aux = list->next;
    long long int indexCounter = 0;

    while (aux != list && indexCounter != index)
    {
        aux = aux->next;
        indexCounter++;
    }
    return ((indexCounter == index) ? aux : NULL);
}

void delete_list_llu(ListLlu **list, long long int index)
{
    if (list == NULL || (*list) == NULL || index < 0)
        return;

    long long int length = length_list_llu((*list));

    if (index >= length)
        return;

    if (index == 0)
    {
        shift_list_llu(list);
        return;
    }
    else if (index == length - 1)
    {
        pop_list_llu(list);
    }
    else
    {
        long long int indexCounter = 0;
        ListLlu *aux = (*list)->next;
        while (indexCounter != index - 1) {
            aux = aux->next;
            indexCounter++;
        }

        if (indexCounter == index - 1) {
            ListLlu *nodeToDelete = aux->next;
            aux->next = nodeToDelete->next;
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}

void free_list_llu(ListLlu **list)
{
    if (list == NULL)
        return;

    ListLlu *aux = (*list)->next;
    while (aux != (*list))
    {
        ListLlu *prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(aux);
    (*list) = NULL;
}

long long unsigned int length_list_llu(ListLlu *list)
{
    if (list == NULL)
        return 0;

    long long unsigned int counter = 0;
    ListLlu *aux = list->next;

    while (aux != list)
    {
        counter++;
        aux = aux->next;
    }
    counter++;

    return counter;
}

bool is_empty_list_llu(ListLlu *list)
{
    return (list == NULL);
}

void print_list_llu(ListLlu *list)
{
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    ListLlu *first = list->next;

    while (first != list)
    {
        printf("%llu ", first->value);
        first = first->next;
    }

    printf("%llu\n", list->value);
}

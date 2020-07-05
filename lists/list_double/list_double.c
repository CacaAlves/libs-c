#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_double.h"

ListDouble *new_node_list_double(double value)
{
    ListDouble *node = (ListDouble *)malloc(sizeof(ListDouble));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_list_double(ListDouble **list, double value)
{
    if (list == NULL)
        return;

    ListDouble *node = new_node_list_double(value);

    if ((*list) == NULL)
    {
        (*list) = node;
        (*list)->next = node;
    }
    else
    {
        ListDouble *last = (*list);
        node->next = last->next;
        last->next = node;
        (*list) = node;
    }
}

void unshift_list_double(ListDouble **list, double value)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_double(list, value);
    }
    else
    {
        ListDouble *node = new_node_list_double(value);
        ListDouble *first = (*list)->next;
        ListDouble *last = (*list);
        last->next = node;
        node->next = first;
    }
}

void pop_list_double(ListDouble **list)
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
        ListDouble *aux = (*list)->next;
        while (aux->next != (*list))
        {
            aux = aux->next;
        }

        aux->next = (*list)->next;
        free(*list);
        (*list) = aux;
    }
}

void shift_list_double(ListDouble **list)
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
        ListDouble *first = (*list)->next;
        (*list)->next = first->next;
        free(first);
        first = NULL;
    }
}

double peek_list_double(ListDouble *list)
{
    if (list != NULL)
    {
        return ((list->next)->value);
    }
}

double top_list_double(ListDouble *list)
{
    if (list != NULL)
    {
        return (list->value);
    }
}

long long int index_of_list_double(ListDouble *list, double value)
{
    if (list == NULL)
        return -1;

    ListDouble *aux = list->next;
    long long int index = 0;

    while (aux != list && aux->value != value)
    {
        aux = aux->next;
        index++;
    }

    return ((aux->value == value) ? index : -1);
}

ListDouble *includes_list_double(ListDouble *list, long long int index)
{
    if (list == NULL || index < 0)
        return NULL;

    ListDouble *aux = list->next;
    long long int indexCounter = 0;

    while (aux != list && indexCounter != index)
    {
        aux = aux->next;
        indexCounter++;
    }
    return ((indexCounter == index) ? aux : NULL);
}

void delete_list_double(ListDouble **list, long long int index)
{
    if (list == NULL || (*list) == NULL || index < 0)
        return;

    long long int length = length_list_double((*list));

    if (index >= length)
        return;

    if (index == 0)
    {
        shift_list_double(list);
        return;
    }
    else if (index == length - 1)
    {
        pop_list_double(list);
    }
    else
    {
        long long int indexCounter = 0;
        ListDouble *aux = (*list)->next;
        while (indexCounter != index - 1) {
            aux = aux->next;
            indexCounter++;
        }

        if (indexCounter == index - 1) {
            ListDouble *nodeToDelete = aux->next;
            aux->next = nodeToDelete->next;
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}

void free_list_double(ListDouble **list)
{
    if (list == NULL)
        return;

    ListDouble *aux = (*list)->next;
    while (aux != (*list))
    {
        ListDouble *prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(aux);
    (*list) = NULL;
}

long long unsigned int length_list_double(ListDouble *list)
{
    if (list == NULL)
        return 0;

    long long unsigned int counter = 0;
    ListDouble *aux = list->next;

    while (aux != list)
    {
        counter++;
        aux = aux->next;
    }
    counter++;

    return counter;
}

bool is_empty_list_double(ListDouble *list)
{
    return (list == NULL);
}

void print_list_double(ListDouble *list)
{
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    ListDouble *first = list->next;

    while (first != list)
    {
        printf("%f ", first->value);
        first = first->next;
    }

    printf("%f\n", list->value);
}

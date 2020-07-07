#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_float.h"

ListFloat *new_node_list_float(float data)
{
    ListFloat *node = (ListFloat *)malloc(sizeof(ListFloat));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_list_float(ListFloat **list, float data)
{
    if (list == NULL)
        return;

    ListFloat *node = new_node_list_float(data);

    if ((*list) == NULL)
    {
        (*list) = node;
        (*list)->next = node;
    }
    else
    {
        ListFloat *last = (*list);
        node->next = last->next;
        last->next = node;
        (*list) = node;
    }
}

void unshift_list_float(ListFloat **list, float data)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_float(list, data);
    }
    else
    {
        ListFloat *node = new_node_list_float(data);
        ListFloat *first = (*list)->next;
        ListFloat *last = (*list);
        last->next = node;
        node->next = first;
    }
}

void pop_list_float(ListFloat **list)
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
        ListFloat *aux = (*list)->next;
        while (aux->next != (*list))
        {
            aux = aux->next;
        }

        aux->next = (*list)->next;
        free(*list);
        (*list) = aux;
    }
}

void shift_list_float(ListFloat **list)
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
        ListFloat *first = (*list)->next;
        (*list)->next = first->next;
        free(first);
        first = NULL;
    }
}

float peek_list_float(ListFloat *list)
{
    if (list != NULL)
    {
        return ((list->next)->data);
    }
}

float top_list_float(ListFloat *list)
{
    if (list != NULL)
    {
        return (list->data);
    }
}

long long int index_of_list_float(ListFloat *list, float data)
{
    if (list == NULL)
        return -1;

    ListFloat *aux = list->next;
    long long int index = 0;

    while (aux != list && aux->data != data)
    {
        aux = aux->next;
        index++;
    }

    return ((aux->data == data) ? index : -1);
}

ListFloat *includes_list_float(ListFloat *list, long long int index)
{
    if (list == NULL || index < 0)
        return NULL;

    ListFloat *aux = list->next;
    long long int indexCounter = 0;

    while (aux != list && indexCounter != index)
    {
        aux = aux->next;
        indexCounter++;
    }
    return ((indexCounter == index) ? aux : NULL);
}

void delete_list_float(ListFloat **list, long long int index)
{
    if (list == NULL || (*list) == NULL || index < 0)
        return;

    long long int length = length_list_float((*list));

    if (index >= length)
        return;

    if (index == 0)
    {
        shift_list_float(list);
        return;
    }
    else if (index == length - 1)
    {
        pop_list_float(list);
    }
    else
    {
        long long int indexCounter = 0;
        ListFloat *aux = (*list)->next;
        while (indexCounter != index - 1) {
            aux = aux->next;
            indexCounter++;
        }

        if (indexCounter == index - 1) {
            ListFloat *nodeToDelete = aux->next;
            aux->next = nodeToDelete->next;
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}

void free_list_float(ListFloat **list)
{
    if (list == NULL)
        return;

    ListFloat *aux = (*list)->next;
    while (aux != (*list))
    {
        ListFloat *prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(aux);
    (*list) = NULL;
}

long long unsigned int length_list_float(ListFloat *list)
{
    if (list == NULL)
        return 0;

    long long unsigned int counter = 0;
    ListFloat *aux = list->next;

    while (aux != list)
    {
        counter++;
        aux = aux->next;
    }
    counter++;

    return counter;
}

bool is_empty_list_float(ListFloat *list)
{
    return (list == NULL);
}

void print_list_float(ListFloat *list)
{
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    ListFloat *first = list->next;

    while (first != list)
    {
        printf("%f ", first->data);
        first = first->next;
    }

    printf("%f\n", list->data);
}

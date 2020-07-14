#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_void.h"

ListVoid *new_node_list_void(void *data)
{
    ListVoid *node = (ListVoid *)malloc(sizeof(ListVoid));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_list_void(ListVoid **list, void *data)
{
    if (list == NULL)
        return;

    ListVoid *node = new_node_list_void(data);

    if ((*list) == NULL)
    {
        (*list) = node;
        (*list)->next = node;
    }
    else
    {
        ListVoid *last = (*list);
        node->next = last->next;
        last->next = node;
        (*list) = node;
    }
}

void unshift_list_void(ListVoid **list, void *data)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_void(list, data);
    }
    else
    {
        ListVoid *node = new_node_list_void(data);
        ListVoid *first = (*list)->next;
        ListVoid *last = (*list);
        last->next = node;
        node->next = first;
    }
}

void pop_list_void(ListVoid **list)
{
    if (list == NULL || (*list) == NULL)
    {
        printf("Can't pop! List is empty.\n");
        return;
    }

    if ((*list)->next == (*list))
    {
        free(*list);
        (*list) = NULL;
    }
    else
    {
        ListVoid *aux = (*list)->next;
        while (aux->next != (*list))
        {
            aux = aux->next;
        }

        aux->next = (*list)->next;
        free(*list);
        (*list) = aux;
    }
}

void shift_list_void(ListVoid **list)
{
    if (list == NULL || (*list) == NULL)
    {
        printf("Can't shift! The list is empty.\n");
        return;
    }

    if ((*list)->next == (*list))
    {
        free(*list);
        (*list) = NULL;
    }
    else
    {
        ListVoid *first = (*list)->next;
        (*list)->next = first->next;
        free(first);
        first = NULL;
    }
}

void *peek_list_void(ListVoid *list)
{
    if (list == NULL)
    {
        printf("Can't peek! List is empty.\n");
    }
    else
    {
        return ((list->next)->data);
    }
}

void *top_list_void(ListVoid *list)
{
    if (list == NULL)
    {
        printf("Can't return top! List is empty.\n");
    }
    else
    {
        return (list->data);
    }
}

long long int index_of_list_void(ListVoid *list, void *data)
{
    if (list == NULL)
        return -1;

    ListVoid *aux = list->next;
    long long int index = 0;

    while (aux != list && aux->data != data)
    {
        aux = aux->next;
        index++;
    }

    return ((aux->data == data) ? index : -1);
}

ListVoid *includes_list_void(ListVoid *list, long long int index)
{
    if (list == NULL || index < 0)
        return NULL;

    ListVoid *aux = list->next;
    long long int indexCounter = 0;

    while (aux != list && indexCounter != index)
    {
        aux = aux->next;
        indexCounter++;
    }
    return ((indexCounter == index) ? aux : NULL);
}

void delete_list_void(ListVoid **list, long long int index)
{
    if (list == NULL || (*list) == NULL)
    {
        printf("Can't delete! List is empty.\n");
        return;
    }
    else if (index < 0)
    {
        printf("Can't delete! Invalid index.\n");
        return;
    }

    long long int length = length_list_void((*list));

    if (index >= length)
    {
        printf("Can't delete! Invalide index.\n");
        return;
    }

    if (index == 0)
    {
        shift_list_void(list);
        return;
    }
    else if (index == length - 1)
    {
        pop_list_void(list);
    }
    else
    {
        long long int indexCounter = 0;
        ListVoid *aux = (*list)->next;
        while (indexCounter != index - 1) {
            aux = aux->next;
            indexCounter++;
        }

        if (indexCounter == index - 1) {
            ListVoid *nodeToDelete = aux->next;
            aux->next = nodeToDelete->next;
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}

void free_list_void(ListVoid **list)
{
    if (list == NULL)
        return;

    ListVoid *aux = (*list)->next;
    while (aux != (*list))
    {
        ListVoid *prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(aux);
    (*list) = NULL;
}

int length_list_void(ListVoid *list)
{
    if (list == NULL)
        return 0;

    int counter = 0;
    ListVoid *aux = list->next;

    while (aux != list)
    {
        counter++;
        aux = aux->next;
    }
    counter++;

    return counter;
}

bool is_empty_list_void(ListVoid *list)
{
    return (list == NULL);
}

void print_list_void(ListVoid *list)
{
    if (list == NULL)
    {
        printf("Can't print! Empty list.\n");
        return;
    }

    ListVoid *first = list->next;

    while (first != list)
    {
        printf("%p ", first->data);
        first = first->next;
    }

    printf("%p\n", list->data);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_char.h"

ListChar *new_node_list_char(char data)
{
    ListChar *node = (ListChar *)malloc(sizeof(ListChar));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_list_char(ListChar **list, char data)
{
    if (list == NULL)
        return;

    ListChar *node = new_node_list_char(data);

    if ((*list) == NULL)
    {
        (*list) = node;
        (*list)->next = node;
    }
    else
    {
        ListChar *last = (*list);
        node->next = last->next;
        last->next = node;
        (*list) = node;
    }
}

void unshift_list_char(ListChar **list, char data)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_char(list, data);
    }
    else
    {
        ListChar *node = new_node_list_char(data);
        ListChar *first = (*list)->next;
        ListChar *last = (*list);
        last->next = node;
        node->next = first;
    }
}

void pop_list_char(ListChar **list)
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
        ListChar *aux = (*list)->next;
        while (aux->next != (*list))
        {
            aux = aux->next;
        }

        aux->next = (*list)->next;
        free(*list);
        (*list) = aux;
    }
}

void shift_list_char(ListChar **list)
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
        ListChar *first = (*list)->next;
        (*list)->next = first->next;
        free(first);
        first = NULL;
    }
}

char peek_list_char(ListChar *list)
{
    if (list != NULL)
    {
        return ((list->next)->data);
    }
}

char top_list_char(ListChar *list)
{
    if (list != NULL)
    {
        return (list->data);
    }
}

long long int index_of_list_char(ListChar *list, char data)
{
    if (list == NULL)
        return -1;

    ListChar *aux = list->next;
    long long int index = 0;

    while (aux != list && aux->data != data)
    {
        aux = aux->next;
        index++;
    }

    return ((aux->data == data) ? index : -1);
}

ListChar *includes_list_char(ListChar *list, long long int index)
{
    if (list == NULL || index < 0)
        return NULL;

    ListChar *aux = list->next;
    long long int indexCounter = 0;

    while (aux != list && indexCounter != index)
    {
        aux = aux->next;
        indexCounter++;
    }
    return ((indexCounter == index) ? aux : NULL);
}

void delete_list_char(ListChar **list, long long int index)
{
    if (list == NULL || (*list) == NULL || index < 0)
        return;

    long long int length = length_list_char((*list));

    if (index >= length)
        return;

    if (index == 0)
    {
        shift_list_char(list);
        return;
    }
    else if (index == length - 1)
    {
        pop_list_char(list);
    }
    else
    {
        long long int indexCounter = 0;
        ListChar *aux = (*list)->next;
        while (indexCounter != index - 1) {
            aux = aux->next;
            indexCounter++;
        }

        if (indexCounter == index - 1) {
            ListChar *nodeToDelete = aux->next;
            aux->next = nodeToDelete->next;
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}

void free_list_char(ListChar **list)
{
    if (list == NULL)
        return;

    ListChar *aux = (*list)->next;
    while (aux != (*list))
    {
        ListChar *prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(aux);
    (*list) = NULL;
}

long long unsigned int length_list_char(ListChar *list)
{
    if (list == NULL)
        return 0;

    long long unsigned int counter = 0;
    ListChar *aux = list->next;

    while (aux != list)
    {
        counter++;
        aux = aux->next;
    }
    counter++;

    return counter;
}

bool is_empty_list_char(ListChar *list)
{
    return (list == NULL);
}

void print_list_char(ListChar *list)
{
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    ListChar *first = list->next;

    while (first != list)
    {
        printf("%c", first->data);
        first = first->next;
    }

    printf("%c\n", list->data);
}

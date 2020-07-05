#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_char.h"

ListChar *new_node_list_char(char value)
{
    ListChar *node = (ListChar *)malloc(sizeof(ListChar));
    node->value = value;
    node->next = NULL;

    return node;
}

void push_list_char(ListChar **list, char value)
{
    if (list == NULL)
        return;

    ListChar *node = new_node_list_char(value);

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

void unshift_list_char(ListChar **list, char value)
{
    if (list == NULL)
        return;

    if ((*list) == NULL)
    {
        push_list_char(list, value);
    }
    else
    {
        ListChar *node = new_node_list_char(value);
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
        return ((list->next)->value);
    }
}

char top_list_char(ListChar *list)
{
    if (list != NULL)
    {
        return (list->value);
    }
}

long long int index_of_list_char(ListChar *list, char value)
{
}

ListChar *includes_list_char(ListChar *list, long long int index)
{
}

void delete_list_char(ListChar **list, long long int index)
{
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
}

void print_list_char(ListChar *list)
{
    if (list == NULL)
        return;

    ListChar *first = list->next;

    while (first != list)
    {
        printf("%c", first->value);
        first = first->next;
    }

    printf("%c\n", list->value);
}

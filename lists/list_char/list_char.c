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
        
    }
}
#include <stdbool.h>

typedef struct ListLlu
{
    long long unsigned int data;
    struct ListLlu *next;
} ListLlu;

void push_list_llu(ListLlu **list, long long unsigned int data);             /*Inserts at the end*/
void unshift_list_llu(ListLlu **list, long long unsigned int data);          /*Inserts at the beginning*/
void pop_list_llu(ListLlu **list);                                           /*Removes at the end*/
void shift_list_llu(ListLlu **list);                                         /*Removes at the beginning*/
long long unsigned int peek_list_llu(ListLlu *list);                         /*Returns the first data*/
long long unsigned int top_list_llu(ListLlu *list);                          /*Returns the the last data*/
long long int index_of_list_llu(ListLlu *list, long long unsigned int data); /*Returns the index of the first node that contains the data*/
ListLlu *includes_list_llu(ListLlu *list, long long int index);              /*Returns the node, if it exists, in the list*/
void delete_list_llu(ListLlu **list, long long int index);                   /*Removes at the index position*/
void free_list_llu(ListLlu **list);                                          /*Frees the list from the memory*/
long long unsigned int length_list_llu(ListLlu *list);                       /*Returns the length of the list*/
bool is_empty_list_llu(ListLlu *list);                                       /*Returns whether the list is empty or not*/
void print_list_llu(ListLlu *list);                                          /*Prints the list*/
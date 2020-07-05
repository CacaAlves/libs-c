#include <stdbool.h>

typedef struct ListLld
{
    long long int value;
    struct ListLld *next;
} ListLld;

void push_list_lld(ListLld **list, long long int value);             /*Inserts at the end*/
void unshift_list_lld(ListLld **list, long long int value);          /*Inserts at the beginning*/
void pop_list_lld(ListLld **list);                                   /*Removes at the end*/
void shift_list_lld(ListLld **list);                                 /*Removes at the beginning*/
long long int peek_list_lld(ListLld *list);                          /*Returns the first value*/
long long int top_list_lld(ListLld *list);                           /*Returns the the last value*/
long long int index_of_list_lld(ListLld *list, long long int value); /*Returns the index of the first node that contains the value*/
ListLld *includes_list_lld(ListLld *list, long long int index);      /*Returns the node, if it exists, in the list*/
void delete_list_lld(ListLld **list, long long int index);           /*Removes at the index position*/
void free_list_lld(ListLld **list);                                  /*Frees the list from the memory*/
long long unsigned int length_list_lld(ListLld *list);               /*Returns the length of the list*/
bool is_empty_list_lld(ListLld *list);                               /*Returns whether the list is empty or not*/
void print_list_lld(ListLld *list);                                  /*Prints the list*/
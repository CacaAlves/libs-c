#include <stdbool.h>

typedef struct ListInt
{
    int value;
    struct ListInt *next;
} ListInt;

void push_list_int(ListInt **list, int value);                  /*Inserts at the end*/
void unshift_list_int(ListInt **list, int value);               /*Inserts at the beginning*/
void pop_list_int(ListInt **list);                              /*Removes at the end*/
void shift_list_int(ListInt **list);                            /*Removes at the beginning*/
int peek_list_int(ListInt *list);                               /*Returns the first value*/
int top_list_int(ListInt *list);                                /*Returns the the last value*/
long long int index_of_list_int(ListInt *list, int value);      /*Returns the index of the first node that contains the value*/
ListInt *includes_list_int(ListInt *list, long long int index); /*Returns the node, if it exists, in the list*/
void delete_list_int(ListInt **list, long long int index);      /*Removes at the index position*/
void free_list_int(ListInt **list);                             /*Frees the list from the memory*/
long long unsigned int length_list_int(ListInt *list);          /*Returns the length of the list*/
bool is_empty_list_int(ListInt *list);                          /*Returns whether the list is empty or not*/
void print_list_int(ListInt *list);                             /*Prints the list*/
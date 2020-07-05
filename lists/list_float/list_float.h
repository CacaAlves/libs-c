#include <stdbool.h>

typedef struct ListFloat
{
    float value;
    struct ListFloat *next;
} ListFloat;

void push_list_float(ListFloat **list, float value);                  /*Inserts at the end*/
void unshift_list_float(ListFloat **list, float value);               /*Inserts at the beginning*/
void pop_list_float(ListFloat **list);                                /*Removes at the end*/
void shift_list_float(ListFloat **list);                              /*Removes at the beginning*/
float peek_list_float(ListFloat *list);                               /*Returns the first value*/
float top_list_float(ListFloat *list);                                /*Returns the the last value*/
long long int index_of_list_float(ListFloat *list, float value);      /*Returns the index of the first node that contains the value*/
ListFloat *includes_list_float(ListFloat *list, long long int index); /*Returns the node, if it exists, in the list*/
void delete_list_float(ListFloat **list, long long int index);        /*Removes at the index position*/
void free_list_float(ListFloat **list);                               /*Frees the list from the memory*/
long long unsigned int length_list_float(ListFloat *list);            /*Returns the length of the list*/
bool is_empty_list_float(ListFloat *list);                            /*Returns whether the list is empty or not*/
void print_list_float(ListFloat *list);                               /*Prints the list*/
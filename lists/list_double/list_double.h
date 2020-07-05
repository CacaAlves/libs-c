#include <stdbool.h>

typedef struct ListDouble
{
    double value;
    struct ListDouble *next;
} ListDouble;

void push_list_double(ListDouble **list, double value);                  /*Inserts at the end*/
void unshift_list_double(ListDouble **list, double value);               /*Inserts at the beginning*/
void pop_list_double(ListDouble **list);                                 /*Removes at the end*/
void shift_list_double(ListDouble **list);                               /*Removes at the beginning*/
double peek_list_double(ListDouble *list);                               /*Returns the first value*/
double top_list_double(ListDouble *list);                                /*Returns the the last value*/
long long int index_of_list_double(ListDouble *list, double value);      /*Returns the index of the first node that contains the value*/
ListDouble *includes_list_double(ListDouble *list, long long int index); /*Returns the node, if it exists, in the list*/
void delete_list_double(ListDouble **list, long long int index);         /*Removes at the index position*/
void free_list_double(ListDouble **list);                                /*Frees the list from the memory*/
long long unsigned int length_list_double(ListDouble *list);             /*Returns the length of the list*/
bool is_empty_list_double(ListDouble *list);                             /*Returns whether the list is empty or not*/
void print_list_double(ListDouble *list);                                /*Prints the list*/
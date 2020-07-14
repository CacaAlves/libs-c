#include <stdbool.h>

typedef struct ListVoid
{
    void *data;
    struct ListVoid *next;
} ListVoid;

void push_list_void(ListVoid **list, void *data);                  /*Inserts at the end*/
void unshift_list_void(ListVoid **list, void *data);               /*Inserts at the beginning*/
void pop_list_void(ListVoid **list);                               /*Removes at the end*/
void shift_list_void(ListVoid **list);                             /*Removes at the beginning*/
void *peek_list_void(ListVoid *list);                              /*Returns the first data*/
void *top_list_void(ListVoid *list);                               /*Returns the the last data*/
long long int index_of_list_void(ListVoid *list, void *data);      /*Returns the index of the first node that contains the data*/
ListVoid *includes_list_void(ListVoid *list, long long int index); /*Returns the node, if it exists, in the list*/
void delete_list_void(ListVoid **list, long long int index);       /*Removes at the index position*/
void free_list_void(ListVoid **list);                              /*Frees the list from the memory*/
int length_list_void(ListVoid *list);                            /*Returns the length of the list*/
bool is_empty_list_void(ListVoid *list);                           /*Returns whether the list is empty or not*/
void print_list_void(ListVoid *list);                              /*Prints the list*/
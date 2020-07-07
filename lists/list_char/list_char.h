#include <stdbool.h>

typedef struct ListChar
{
    char data;
    struct ListChar *next;
} ListChar;

void push_list_char(ListChar **list, char data);                   /*Inserts at the end*/
void unshift_list_char(ListChar **list, char data);                /*Inserts at the beginning*/
void pop_list_char(ListChar **list);                               /*Removes at the end*/
void shift_list_char(ListChar **list);                             /*Removes at the beginning*/
char peek_list_char(ListChar *list);                               /*Returns the first data*/
char top_list_char(ListChar *list);                                /*Returns the the last data*/
long long int index_of_list_char(ListChar *list, char data);       /*Returns the index of the first node that contains the data*/
ListChar *includes_list_char(ListChar *list, long long int index); /*Returns the node, if it exists, in the list*/
void delete_list_char(ListChar **list, long long int index);       /*Removes at the index position*/
void free_list_char(ListChar **list);                              /*Frees the list from the memory*/
long long unsigned int length_list_char(ListChar *list);           /*Returns the length of the list*/
bool is_empty_list_char(ListChar *list);                           /*Returns whether the list is empty or not*/
void print_list_char(ListChar *list);                              /*Prints the list*/
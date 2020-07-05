#include <stdbool.h>

typedef struct ListChar
{
    char value;
    struct ListChar *next;
} ListChar;

void push_list_char(ListChar **list, char value);    /*Inserts at the end*/
void unshift_list_char(ListChar **list, char value); /*Inserts at the beginning*/
void pop_queue_char(ListChar **list);                /*Removes at the end*/
void shift_list_char(ListChar **list);               /*Removes at the beginning*/
char peek_list_char(ListChar *list);                 /*Returns the first value*/
char top_list_char(ListChar *list);                  /*Returns the the last value*/
bool is_empty_list_char(ListChar *list);             /*Returns whether the list is empty or not*/
void print_queue_char(ListChar **list);              /*Prints the list*/
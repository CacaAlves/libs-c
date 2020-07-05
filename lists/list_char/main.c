#include <stdio.h>
#include "list_char.h"

void main()
{
    ListChar *list = NULL;
    unshift_list_char(&list, '2');
    push_list_char(&list, '3');
    unshift_list_char(&list, '1');
    push_list_char(&list, '4');
    push_list_char(&list, '5');

    // print_list_char(list);
    // pop_list_char(&list);
    // print_list_char(list);
    // pop_list_char(&list);
    // print_list_char(list);
    // pop_list_char(&list);
    // print_list_char(list);
    // pop_list_char(&list);
    // print_list_char(list);
    // pop_list_char(&list);
    // print_list_char(list);

    // print_list_char(list);
    // shift_list_char(&list);
    // print_list_char(list);
    // shift_list_char(&list);
    // print_list_char(list);
    // shift_list_char(&list);
    // print_list_char(list);
    // shift_list_char(&list);
    // print_list_char(list);
    // shift_list_char(&list);
    // print_list_char(list);

    // printf("%c\n", peek_list_char(list));
    // free_list_char(&list);
    // printf("%c\n", peek_list_char(list));

    // printf("%c\n", top_list_char(list));
    // free_list_char(&list);
    // printf("%c\n", top_list_char(list));

    // printf("%llu\n", length_list_char(list));
    // free_list_char(&list);
    // printf("%llu\n", length_list_char(list));
    // push_list_char(&list, '1');
    // printf("%llu\n", length_list_char(list));

}
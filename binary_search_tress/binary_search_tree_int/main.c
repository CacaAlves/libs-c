#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree_int.h"

void main()
{
    BstInt *root = NULL;
    insert_bst_int(&root, 30);
    insert_bst_int(&root, 4);
    insert_bst_int(&root, 0);
    insert_bst_int(&root, -1);
    insert_bst_int(&root, 5);
    insert_bst_int(&root, 33);
    insert_bst_int(&root, 13);
    insert_bst_int(&root, -3);
    insert_bst_int(&root, -33);
    insert_bst_int(&root, 43);
    insert_bst_int(&root, 3);
    insert_bst_int(&root, 34);
    insert_bst_int(&root, 2);
    insert_bst_int(&root, 1);
    // insert_bst_int(&root, 0);

    // int dataToSearch = 2;
    // int resultOfSearch = search_bst_int(root, dataToSearch);
    // if (resultOfSearch == 1)
    // {
    //     printf("The data %d was found int the tree\n", dataToSearch);
    // }
    // else
    // {
    //     printf("The data %d was NOT found int the tree\n", dataToSearch);
    // }

    // int min = find_min_bst_int(root);
    // printf("Min: %d\n", min);
    // int max = find_max_bst_int(root);
    // printf("Max: %d\n", max);

    // root = NULL;
    // insert_bst_int(&root, 1);
    // insert_bst_int(&root, 3);
    // insert_bst_int(&root, 7);
    // insert_bst_int(&root, 9);

    // printf("Height: %d\n", find_height_bst_int(root));

    // print_bst_int_reverse(root);
    // printf("\n");

    // root->left = (BstInt *)malloc(sizeof(BstInt));
    // root->left->data = 31;
    // bool isBinarySearchTree = is_bst_int(root);
    // char *isBst = (isBinarySearchTree ? "It's bst!\n" : "It isn't bst!\n");
    // printf("%s", isBst);

    // int array[] = {30, 4, 0, -1, 5, 33, -999, 13, -3, -33, 43, 3, 34, 2, 1};

    // for (int i = 0; i <= 15; i++)
    // {
    //     print_bst_int_by_breadth(root);
    //     root = delete_bst_int(root, array[i]);
    // }

    printf("%d\n", (inorder_successor(root, -3))->data);
    print_bst_int_by_depth_inorder(root);
}
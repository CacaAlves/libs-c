#include <stdbool.h>
typedef struct BstInt
{
    int data;
    struct BstInt *left;
    struct BstInt *right;
} BstInt;

void insert_bst_int(BstInt **root, int data);
BstInt *search_node_bst_int(BstInt *root, int data);
int find_min_bst_int(BstInt *root);
int find_max_bst_int(BstInt *root);
int find_height_bst_int(BstInt *root);
bool is_bst_int(BstInt *root);
BstInt *inorder_successor(BstInt *root, int value);
BstInt *delete_bst_int(BstInt *root, int value);
void print_bst_int_by_depth_preorder(BstInt *root);
void print_bst_int_by_depth_inorder(BstInt *root);
void print_bst_int_by_depth_postorder(BstInt *root);
void print_bst_int_reverse(BstInt *root);
void print_bst_int_by_breadth(BstInt *root);

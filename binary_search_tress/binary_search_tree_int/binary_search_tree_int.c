#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree_int.h"
#include "queue_void.h"

BstInt *new_node_bst_int(int data)
{
    BstInt *node = (BstInt *)malloc(sizeof(BstInt));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int max_compare_int(int data1, int data2)
{
    return ((data1 >= data2) ? data1 : data2);
}

void insert_bst_int(BstInt **root, int data)
{
    if (root == NULL)
        return;

    BstInt *node = new_node_bst_int(data);

    if ((*root) == NULL)
    {
        (*root) = node;
    }
    else if (data < (*root)->data)
    {
        insert_bst_int(&((*root)->left), data);
    }
    else if (data > (*root)->data)
    {
        insert_bst_int(&((*root)->right), data);
    }
}

BstInt *search_node_bst_int(BstInt *root, int data)
{

    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == data)
    {
        return root;
    }
    else if (root->data > data)
    {
        return search_node_bst_int(root->left, data);
    }
    else
    {
        return search_node_bst_int(root->right, data);
    }
}

int find_min_bst_int(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't find! Empty tree.\n");
        return -1;
    }

    int min = root->data;

    if (root->left != NULL)
    {
        min = find_min_bst_int(root->left);
    }
    return min;
}

BstInt *find_min_node_bst_int(BstInt *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    BstInt *min = root;

    if (root->left != NULL)
    {
        min = find_min_node_bst_int(root->left);
    }
    return min;
}

int find_max_bst_int(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't find! Empty tree.\n");
        return -1;
    }

    int max = root->data;

    if (root->right != NULL)
    {
        max = find_max_bst_int(root->right);
    }
    return max;
}

int find_height_bst_int(BstInt *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return (max_compare_int(find_height_bst_int(root->left), find_height_bst_int(root->right)) + 1);
}

bool is_bst_util_int(BstInt *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    return (root->data > minValue && root->data < maxValue && is_bst_util_int(root->left, minValue, root->data) && is_bst_util_int(root->right, root->data, maxValue));
}

bool is_bst_int(BstInt *root)
{
    return is_bst_util_int(root, (-__INT_MAX__ - 1), __INT_MAX__);
}

BstInt *delete_bst_int(BstInt *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->data)
    {
        root->left = delete_bst_int(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_bst_int(root->right, value);
    }
    else
    {
        /* Wohoo... I found you, get ready to be deleted */

        /*Case 1: No child*/
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        /*Case 2: One child*/
        else if (root->left == NULL)
        {
            BstInt *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            BstInt *temp = root;
            root = root->left;
            free(temp);
        }
        /*Case 3: Two children*/
        else
        {
            BstInt *temp = find_min_node_bst_int(root->right);
            root->data = temp->data;
            root->right = delete_bst_int(root->right, temp->data);
        }
    }

    return root;
}

BstInt *inorder_successor(BstInt *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data < value)
    {
        BstInt *node = inorder_successor(root->right, value);
        return (node != NULL ? node : root);
    }
    else if (root->data > value)
    {
        BstInt *node = inorder_successor(root->left, value);
        return (node != NULL ? node : root);
    }
    else 
    {
        /*Wohoo, find you*/
        BstInt *node = find_min_node_bst_int(root->right);
        return node;
    }
}

void print_bst_int_by_depth_preorder(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't print! Empty tree.\n");
        return;
    }

    printf("%d ", root->data);

    if (root->left != NULL)
    {
        print_bst_int_by_depth_preorder(root->left);
    }
    if (root->right != NULL)
    {
        print_bst_int_by_depth_preorder(root->right);
    }
}

void print_bst_int_by_depth_inorder(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't print! Empty tree.\n");
        return;
    }

    if (root->left != NULL)
    {
        print_bst_int_by_depth_inorder(root->left);
    }

    printf("%d ", root->data);

    if (root->right != NULL)
    {
        print_bst_int_by_depth_inorder(root->right);
    }
}

void print_bst_int_by_depth_postorder(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't print! Empty tree.\n");
        return;
    }

    if (root->left != NULL)
    {
        print_bst_int_by_depth_postorder(root->left);
    }
    if (root->right != NULL)
    {
        print_bst_int_by_depth_postorder(root->right);
    }

    printf("%d ", root->data);
}

void print_bst_int_reverse(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't print! Empty tree.\n");
        return;
    }

    if (root->right != NULL)
    {
        print_bst_int_reverse(root->right);
    }

    printf("%d ", root->data);

    if (root->left != NULL)
    {
        print_bst_int_reverse(root->left);
    }
}

void print_bst_int_by_breadth(BstInt *root)
{
    if (root == NULL)
    {
        printf("Can't print! Empty tree.\n");
        return;
    }

    QueueVoid *queue = NULL;
    enqueue_queue_void(&queue, root);

    while (!is_empty_queue_void(queue))
    {
        BstInt *current = (BstInt *)peek_queue_void(queue);
        printf("%d ", current->data);
        if (current->left != NULL)
        {
            enqueue_queue_void(&queue, current->left);
        }
        if (current->right != NULL)
        {
            enqueue_queue_void(&queue, current->right);
        }
        dequeue_queue_void(&queue);
    }
    printf("\n");
}
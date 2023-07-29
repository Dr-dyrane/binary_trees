#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
    binary_tree_t *node;
    struct levelorder_queue_s *next;
} levelorder_queue_t;

/* Printing helper function */
void binary_tree_print(const binary_tree_t *tree);

/* Task 0 - Create a new binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 1 - Insert a node as the left child of a given node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Task 2 - Insert a node as the right child of a given node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Task 3 - Delete an entire binary tree */
void binary_tree_delete(binary_tree_t *tree);

/* Task 4 - Check if a node is a leaf node */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Task 5 - Check if a node is the root of the binary tree */
int binary_tree_is_root(const binary_tree_t *node);

/* Task 6 - Perform a preorder traversal of the binary tree */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Task 7 - Perform an inorder traversal of the binary tree */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Task 8 - Perform a postorder traversal of the binary tree */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Task 9 - Calculate the height of the binary tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* Task 10 - Calculate the depth (level) of a node in the binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Task 11 - Calculate the size (number of nodes) of the binary tree */
size_t binary_tree_size(const binary_tree_t *tree);

/* Task 12 - Count the number of leaf nodes in the binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Task 13 - Count  number of nodes with at least 1 child : the binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Task 14 - Check the balance factor of the binary tree */
int binary_tree_balance(const binary_tree_t *tree);

/* Task 15 - Check if the binary tree is a full binary tree */
int binary_tree_is_full(const binary_tree_t *tree);

/* Task 16 - Check if the binary tree is a perfect binary tree */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Task 17 - Find the sibling of a node in the binary tree */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* Task 18 - Find the uncle of a node in the binary tree */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Task 100 - Find the lowest common ancestor of two nodes */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second);

/* Task 101 - Perform a level-order traversal of the binary tree */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Task 102 - Check if the binary tree is complete */
int binary_tree_is_complete(const binary_tree_t *tree);

/* Task 103 - Perform a left rotation on the binary tree */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* Task 104 - Perform a right rotation on the binary tree */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* Task 110 - Check if the binary tree is a binary search tree (BST) */
int binary_tree_is_bst(const binary_tree_t *tree);

/* Task 111 - Insert a node into a binary search tree (BST) */
bst_t *bst_insert(bst_t **tree, int value);

/* Task 112 - Create a binary search tree (BST) from an array */
bst_t *array_to_bst(int *array, size_t size);

/* Task 113 - Search for a node in a binary search tree (BST) */
bst_t *bst_search(const bst_t *tree, int value);

/* Task 114 - Remove a node from a binary search tree (BST) */
bst_t *bst_remove(bst_t *root, int value);

/* Task 120 - Check if the binary tree is an AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree);

/* Task 121 - Insert a node into an AVL tree */
avl_t *avl_insert(avl_t **tree, int value);

/* Task 122 - Create an AVL tree from an array */
avl_t *array_to_avl(int *array, size_t size);

/* Task 123 - Remove a node from an AVL tree */
avl_t *avl_remove(avl_t *root, int value);

/* Task 124 - Create an AVL tree from a sorted array */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Task 130 - Check if the binary tree is a binary heap */
int binary_tree_is_heap(const binary_tree_t *tree);

/* Task 131 - Insert a node into a binary heap */
heap_t *heap_insert(heap_t **root, int value);

/* Task 132 - Create a binary heap from an array */
heap_t *array_to_heap(int *array, size_t size);

/* Task 133 - Extract the root node from a binary heap */
int heap_extract(heap_t **root);

/* Task 134 - Convert a binary heap to a sorted array */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */

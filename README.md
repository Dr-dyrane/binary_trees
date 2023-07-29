# Binary Trees Project

## Table of Contents

1. [Introduction](#introduction)
2. [Project Description](#project-description)
3. [Project Structure](#project-structure)
4. [Requirements](#requirements)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Functionality](#functionality)
8. [Example Usage](#example-usage)
9. [Contributing](#contributing)
10. [Author](#author)
11. [License](#license)

## Introduction <a name="introduction"></a>

Welcome to the Binary Trees project! This project is a collection of functions and data structures related to binary trees in the C programming language. Binary trees are hierarchical tree structures commonly used in computer science to organize data in a non-linear format. In this project, we'll be implementing various operations and functionalities for binary trees, including binary search trees (BSTs), AVL trees, heaps, and more.

## Project Description <a name="project-description"></a>

The goal of this project is to provide a comprehensive set of functions and data structures that allow users to create, manipulate, and analyze binary trees. The project contains a header file named `binary_trees.h`, which includes the function prototypes and necessary data structures.

The project is structured as follows:

- The `binary_trees.h` header file contains function prototypes and necessary structures for binary trees.
- The source files (.c files) in the repository contain the implementations of the functions defined in the header file.
- The `binary_tree_print.c` file includes a helper function to print binary trees for visualization.

## Project Structure <a name="project-structure"></a>

The project contains the following files:

- `binary_trees.h`: The header file that contains function prototypes and data structures related to binary trees.
- Source Files (.c):
  - `0-binary_tree_node.c`: Function to create a new binary tree node.
  - `1-binary_tree_insert_left.c`: Function to insert a node as the left child of a given node.
  - `2-binary_tree_insert_right.c`: Function to insert a node as the right child of a given node.
  - `3-binary_tree_delete.c`: Function to delete an entire binary tree.
  - `4-binary_tree_is_leaf.c`: Function to check if a node is a leaf node.
  - `5-binary_tree_is_root.c`: Function to check if a node is the root of the binary tree.
  - `6-binary_tree_preorder.c`: Function to perform a preorder traversal of the binary tree.
  - `7-binary_tree_inorder.c`: Function to perform an inorder traversal of the binary tree.
  - `8-binary_tree_postorder.c`: Function to perform a postorder traversal of the binary tree.
  - `9-binary_tree_height.c`: Function to calculate the height of the binary tree.
  - `10-binary_tree_depth.c`: Function to calculate the depth (level) of a node in the binary tree.
  - `11-binary_tree_size.c`: Function to calculate the size (number of nodes) of the binary tree.
  - `12-binary_tree_leaves.c`: Function to count the number of leaf nodes in the binary tree.
  - `13-binary_tree_nodes.c`: Function to count the number of nodes with at least one child in the binary tree.
  - `14-binary_tree_balance.c`: Function to check the balance factor of the binary tree.
  - `15-binary_tree_is_full.c`: Function to check if the binary tree is a full binary tree.
  - `16-binary_tree_is_perfect.c`: Function to check if the binary tree is a perfect binary tree.
  - `17-binary_tree_sibling.c`: Function to find the sibling of a node in the binary tree.
  - `18-binary_tree_uncle.c`: Function to find the uncle of a node in the binary tree.
  - `100-binary_trees_ancestor.c`: Function to find the lowest common ancestor of two nodes.
  - `101-binary_tree_levelorder.c`: Function to perform a level-order traversal of the binary tree.
  - `102-binary_tree_is_complete.c`: Function to check if the binary tree is complete.
  - `103-binary_tree_rotate_left.c`: Function to perform a left rotation on the binary tree.
  - `104-binary_tree_rotate_right.c`: Function to perform a right rotation on the binary tree.
  - `110-binary_tree_is_bst.c`: Function to check if the binary tree is a binary search tree (BST).
  - `111-bst_insert.c`: Function to insert a node into a binary search tree (BST).
  - `112-array_to_bst.c`: Function to create a binary search tree (BST) from an array.
  - `113-bst_search.c`: Function to search for a node in a binary search tree (BST).
  - `114-bst_remove.c`: Function to remove a node from a binary search tree (BST).
  - `120-binary_tree_is_avl.c`: Function to check if the binary tree is an AVL tree.
  - `121-avl_insert.c`: Function to insert a node into an AVL tree.
  - `122-array_to_avl.c`: Function to create an AVL tree from an array.
  - `123-avl_remove.c`: Function to remove a node from an AVL tree.
  - `124-sorted_array_to_avl.c`: Function to create an AVL tree from a sorted array.
  - `130-binary_tree_is_heap.c`: Function to check if the binary tree is a binary heap.
  - `131-heap_insert.c`: Function to insert a node into a binary heap.
  - `132-array_to_heap.c`: Function to create a binary heap from an array.
  - `133-heap_extract.c`: Function to extract the root node from a binary heap.
  - `134-heap_to_sorted_array.c`: Function to convert a binary heap to a sorted array.
  - `140-binary_tree_is_bst.c`: Function to check if the binary tree is a binary search tree (BST).
  - `141-binary_tree_balance.c`: Function to check the balance factor of the binary tree.
  - `142-binary_tree_is_avl.c`: Function to check if the binary tree is an AVL tree.
  - `143-binary_tree_is_heap.c`: Function to check if the binary tree is a binary heap.
  - `144-binary_tree_is_complete.c`: Function to check if the binary tree is a complete binary tree.
  - `145-binary_tree_insert_left.c`: Function to insert a node as the left child of a given node.
  - `146-binary_tree_insert_right.c`: Function to insert a node as the right child of a given node.
  - `147-binary_tree_delete.c`: Function to delete an entire binary tree.
  - `148-binary_tree_rotate_left.c`: Function to perform a left rotation on the binary tree.
  - `149-binary_tree_rotate_right.c`: Function to perform a right rotation on the binary tree.
  - `150-binary_tree_is_full.c`: Function to check if the binary tree is a full binary tree.
  - `151-binary_tree_leaves.c`: Function to count the number of leaf nodes in the binary tree.
  - `152-binary_tree_nodes.c`: Function to count the number of nodes with at least one child in the binary tree.
  - `153-binary_tree_height.c`: Function to calculate the height

of the binary tree.

- `154-binary_tree_balance.c`: Function to check the balance factor of the binary tree.
- `155-binary_tree_is_perfect.c`: Function to check if the binary tree is a perfect binary tree.
- `156-binary_tree_sibling.c`: Function to find the sibling of a node in the binary tree.
- `157-binary_tree_uncle.c`: Function to find the uncle of a node in the binary tree.
- `158-binary_trees_ancestor.c`: Function to find the lowest common ancestor of two nodes.
- `159-binary_tree_levelorder.c`: Function to perform a level-order traversal of the binary tree.
- `160-binary_tree_is_complete.c`: Function to check if the binary tree is complete.
- `161-binary_tree_rotate_left.c`: Function to perform a left rotation on the binary tree.
- `162-binary_tree_rotate_right.c`: Function to perform a right rotation on the binary tree.
- `163-binary_tree_is_bst.c`: Function to check if the binary tree is a binary search tree (BST).
- `164-bst_insert.c`: Function to insert a node into a binary search tree (BST).
- `165-array_to_bst.c`: Function to create a binary search tree (BST) from an array.
- `166-bst_search.c`: Function to search for a node in a binary search tree (BST).
- `167-bst_remove.c`: Function to remove a node from a binary search tree (BST).
- `168-binary_tree_is_avl.c`: Function to check if the binary tree is an AVL tree.
- `169-avl_insert.c`: Function to insert a node into an AVL tree.
- `170-array_to_avl.c`: Function to create an AVL tree from an array.
- `171-avl_remove.c`: Function to remove a node from an AVL tree.
- `172-sorted_array_to_avl.c`: Function to create an AVL tree from a sorted array.
- `180-binary_tree_is_heap.c`: Function to check if the binary tree is a binary heap.
- `181-heap_insert.c`: Function to insert a node into a binary heap.
- `182-array_to_heap.c`: Function to create a binary heap from an array.
- `183-heap_extract.c`: Function to extract the root node from a binary heap.
- `184-heap_to_sorted_array.c`: Function to convert a binary heap to a sorted array.
- `binary_tree_print.c`: Helper function to print binary trees for visualization.
- `README.md`: This detailed README file describing the project and its functionalities.

## Requirements <a name="requirements"></a>

To run this project, you will need the following:

- A computer with Ubuntu 20.04 LTS or compatible Linux distribution.
- GCC (GNU Compiler Collection) installed.
- A C programming environment (text editor or IDE).
- Access to a terminal or command line interface.

## Installation <a name="installation"></a>

To install and use this project, follow these steps:

1. Open a terminal on your Linux system.
2. Clone the project repository from GitHub using the following command:
   ```
   git clone https://github.com/Dr-dyrane/binary_trees.git
   ```
3. Change directory to the project folder:
   ```
   cd binary_trees
   ```
4. Compile the source files using GCC to create the executable:
   ```
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o binary_trees
   ```

## Usage <a name="usage"></a>

To use the compiled executable, run the following command in the terminal:

```
./binary_trees
```

## Functionality <a name="functionality"></a>

This project provides a variety of functions and data structures related to binary trees. Some of the main functionalities include:

- Creating a new binary tree node.
- Inserting nodes as the left or right child of a given node.
- Deleting an entire binary tree.
- Performing preorder, inorder, and postorder traversals of the binary tree.
- Calculating the height, depth, size, number of leaves, and number of nodes in the binary tree.
- Checking if the binary tree is a binary search tree (BST), AVL tree, binary heap, full binary tree, or perfect binary tree.
- Finding the sibling and uncle of a node in the binary tree.
- Finding the lowest common ancestor of two nodes in the binary tree.
- Performing level-order traversal of the binary tree.
- Rotating the binary tree left or right.
- Converting arrays to binary search trees (BST) or AVL trees.
- Removing nodes from binary search trees (BST) or AVL trees.
- Converting binary heaps to sorted arrays.

Please refer to the header file `binary_trees.h` for the complete list of function prototypes and descriptions.

## Example Usage <a name="example-usage"></a>

Here is an example of how to use some of the functionalities provided by the Binary Trees project:

```c
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
    /* Create a binary tree */
    binary_tree_t *root = binary_tree_node(NULL, 10);
    root->left = binary_tree_node(root, 5);
    root->right = binary_tree_node(root, 15);
    root->left->left = binary_tree_node(root->left, 3);
    root->left->right = binary_tree_node(root->left, 7);

    /* Print the binary tree */
    binary_tree_print(root);

    /* Perform a preorder traversal */
    printf("Preorder traversal: ");
    binary_tree_preorder(root, print_number);
    printf("\n");

    /* Calculate the height of the tree */
    printf("Height of the tree: %lu\n", binary_tree_height(root));

    /* Check if the tree is a binary search tree (BST) */
    printf("Is the tree a BST? %d\n", binary_tree_is_bst(root));

    /* Insert a node into the binary search tree */
    bst_t *bst_root = NULL;
    bst_insert(&bst_root, 8);
    bst_insert(&bst_root, 12);
    bst_insert(&bst_root, 20);
    bst_insert(&bst_root, 4);
    binary_tree_print(bst_root);

    /* Remove a node from the binary search tree */
    bst_root = bst_remove(bst_root, 12);
    binary_tree_print(bst_root);

    /* Convert an array to an AVL tree */
    int array[] = {10, 20, 5, 15, 30};
    size_t size = sizeof(array) / sizeof(array[0]);
    avl_t *avl_root = array_to_avl(array, size);
    binary_tree_print(avl_root);

    /* Free the binary trees */
    binary_tree_delete(root);
    binary_tree_delete(bst_root);
    binary_tree_delete(avl_root);

    return (0);
}
```

## Contributing <a name="contributing"></a>

Contributions to this Binary Trees project are welcome. If you find any issues, want to add new functionalities, or improve existing ones, feel free to submit a pull request.

## Author <a name="author"></a>

This Binary Trees project was created and maintained by Alexander Udeogaranya. You can find the

original repository on GitHub at [https://github.com/Dr-dyrane/binary_trees](https://github.com/Dr-dyrane/binary_trees).

## License <a name="license"></a>

This project is licensed under the MIT License. See the `LICENSE` file for details.

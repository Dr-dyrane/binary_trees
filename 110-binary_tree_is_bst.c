#include "binary_trees.h"

/**
 * in_order_validation - Helper function to perform in-order
 * traversal and validate BST.
 * @node: The current node being visited during in-order traversal.
 * @data: Pointer to validation_data_t to hold validation data.
 *
 * Return: 1 if the subtree rooted at 'node' is a valid BST, otherwise 0.
 */
int in_order_validation(const binary_tree_t *node, validation_data_t *data)
{
	if (node == NULL)
		return (1);

	/* Visit left subtree */
	if (!in_order_validation(node->left, data))
		return (0);

	/* Check current node's value */
	if (node->n <= data->prev_value)
	{
		data->has_duplicates = 1;
		return (0);
	}

	/* Update previous value */
	data->prev_value = node->n;

	/* Visit right subtree */
	return (in_order_validation(node->right, data));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 *
 * Description: This function checks if the binary tree is a
 * valid Binary Search Tree.
 *             A Binary Search Tree (BST) is a binary tree where for each node:
 *             - The left subtree contains only nodes with values less
 *             than the node's value.
 *             - The right subtree contains only nodes with values greater
 *             than the node's value.
 *             - Both the left and right subtrees are also BSTs.
 *             This implementation uses in-order traversal to validate the BST.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	validation_data_t data;

	data.prev_value = INT_MIN;

	data.has_duplicates = 0;

	/* Perform in-order traversal and validate BST */
	if (!in_order_validation(tree, &data))
		return (0);

	/* If duplicates are found, the tree is not a valid BST */
	if (data.has_duplicates)
		return (0);

	/* If all conditions are satisfied, the tree is a valid BST. */
	return (1);
}

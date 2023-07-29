#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Calculate the height of the left and right subtrees. */
	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	/* Calculate the balance factor (difference in heights). */
	return (left_height - right_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Calculate the height of the left and right subtrees. */
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/* Return the maximum height between the left and right subtrees plus 1. */
	return (1 + (left_height > right_height ? left_height : right_height));
}

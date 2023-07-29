#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The size of the tree, or 0 if the tree is empty or NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Recursively get the size of the left and right subtrees. */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if the tree is empty or NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Recursively get the height of the left and right subtrees. */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return the maximum height of the subtrees, plus 1 for the current node. */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height, max_nodes;

	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Get the size and height of the tree. */
	size = binary_tree_size(tree);
	height = binary_tree_height(tree);

	/* Calculate the maximum number of nodes for a perfect tree. */
	max_nodes = (1 << height) - 1;

	/* Check if the size of the tree is equal to the maximum number of nodes. */
	if (size == max_nodes)
		return (1);

	return (0);
}

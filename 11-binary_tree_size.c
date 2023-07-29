#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree (number of nodes).
 * @tree: Pointer to the root node of the binary tree.
 *
 * Description: The size of a binary tree is the total number of nodes in it.
 * If `tree` is NULL, the size is 0.
 *
 * Return: The size of the binary tree, or 0 if `tree` is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Recursively calculate the size of the left and right subtrees */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Description: The height of a binary tree is the number of edges between
 * the root node and its furthest leaf node. If `tree` = NULL, the height is 0.
 *
 * Return: The height of the binary tree, or 0 if `tree` is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/**
	 * Return the maximum of the two heights,
	 * plus 1 to account for the current node
	 */
	return (1 + (left_height > right_height ? left_height : right_height));
}

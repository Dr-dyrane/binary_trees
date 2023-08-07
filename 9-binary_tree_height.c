#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns
 *        the height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* If the tree is NULL, return height as 0 */
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		/* Recursively calculate the height of the left subtree */
		if (tree->left)
			left_height = 1 + binary_tree_height(tree->left);

		/* Recursively calculate the height of the right subtree */
		if (tree->right)
			right_height = 1 + binary_tree_height(tree->right);

		/* Return the maximum height between the left and right subtrees */
		return (left_height > right_height ? left_height : right_height);
	}

	/* If the tree is NULL, return 0 as specified in the requirements. */
	return (0);
}

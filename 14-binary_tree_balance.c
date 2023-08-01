#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns the
 *        balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* If the tree is NULL, return balance factor as 0 */
	if (tree)
	{
		/* Calculate the height of the left and right subtrees */
		int left_height = binary_tree_height(tree->left);
		int right_height = binary_tree_height(tree->right);

		/* Return the balance factor (difference in heights) */
		return (left_height - right_height);
	}

	/* If the tree is NULL, return 0 as specified in the requirements. */
	return (0);
}

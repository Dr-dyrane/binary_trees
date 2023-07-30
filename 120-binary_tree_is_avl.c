#include "binary_trees.h"

/**
 * measure_height - Helper function to measure the height of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree.
 *
 * Description: This function recursively calculates - height of a binary tree.
 *             It computes the height of both the left and right subtrees and
 *             returns the maximum height among them,
 *             plus one to account for the
 *             current node itself.
 */
size_t measure_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = measure_height(tree->left);
	size_t right_height = measure_height(tree->right);

	/**
	 * Return the maximum height of the left and right subtrees
	 * plus one for the current node.
	 */
	return (1 + ((left_height > right_height) ? left_height : right_height));
}

/**
 * is_avl_recursive - Helper function to check if binary tree - valid AVL tree.
 * @tree: A pointer to the root node of the binary tree.
 * @min: The minimum allowed value for the nodes in the subtree.
 * @max: The maximum allowed value for the nodes in the subtree.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 *
 * Description: This function recursively checks binary tree - valid AVL tree.
 *             An AVL tree is a binary tree where
 *             the difference between the heights
 *             of the left and right subtrees of every node is at most 1,
 *             and both the left and right subtrees are also AVL trees.
 *             Additionally, it checks if the values of the nodes in
 *             the subtree are within the specified range
 *             (min and max) to satisfy the binary search tree property.
 */
int is_avl_recursive(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	/* Measure the height of the left and right subtrees.*/
	size_t left_height = measure_height(tree->left);
	size_t right_height = measure_height(tree->right);

	/**
	 * Calculate the balance factor
	 * (difference in heights of left and right subtrees).
	 */
	int balance = (int)(left_height - right_height);

	/**
	 * Check if the AVL and binary search tree properties
	 * are satisfied for the current node.
	 */
	if (balance < -1 || balance > 1 || tree->n < min || tree->n > max)
		return (0);

	/* Recursively check the left and right subtrees.*/
	return (is_avl_recursive(tree->left, min, tree->n - 1) &&
		is_avl_recursive(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 *
 * Description: This function checks if the binary tree is a valid AVL tree
 *             by calling the helper function is_avl_recursive
 *             with appropriate parameters.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Call the helper function with the initial minimum and maximum values.*/
	return (is_avl_recursive(tree, INT_MIN, INT_MAX));
}

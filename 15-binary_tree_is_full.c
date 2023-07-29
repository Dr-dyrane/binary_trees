#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Check if the current node is a leaf (base case for recursion). */
	if (binary_tree_is_leaf(tree))
		return (1);

	/* Check if the node has two children and both subtrees are full. */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If only one subtree exists, the tree is not full. */
	return (0);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node is NULL (base case for recursion). */
	if (!node)
		return (0);

	/* Check if the node has no left and right children (leaf node). */
	if (!node->right && !node->left)
		return (1);
	else
		return (0);
}

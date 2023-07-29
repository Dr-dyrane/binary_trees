#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts: nodes with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The number of nodes with at least one child in the tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Check if the tree is empty or NULL (base case for recursion). */
	if (tree == NULL)
		return (0);

	/* Check if the current node has at least one child (not a leaf node). */
	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	else
		return (0); /*Current node is a leaf (no children). */
}

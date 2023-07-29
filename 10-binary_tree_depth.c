#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth of.
 *
 * Description: The depth of a node is the number of edges between the
 * node and the root of the binary tree. If `tree` is NULL, the depth is 0.
 *
 * Return: The depth of the node, or 0 if `tree` is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	/* Traverse up the tree to the root while incrementing depth */
	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

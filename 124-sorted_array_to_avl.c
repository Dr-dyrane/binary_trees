#include "binary_trees.h"

/**
 *is_complete_tree - Check if the tree is a complete tree.
 *@tree: A pointer to the root node of the tree.
 *@index: Current index of the node (starting from 0).
 *@node_count: Total number of nodes in the tree.
 *
 *Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_tree(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_tree(tree->left, 2 *index + 1, node_count) &&
		is_complete_tree(tree->right, 2 *index + 2, node_count));
}

/**
 *binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *@tree: A pointer to the root node of the tree to check.
 *
 *Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_complete_tree(tree, 0, binary_tree_size(tree)))
		return (0);

	if (tree->left && tree->n < tree->left->n)
		return (0);

	if (tree->right && tree->n < tree->right->n)
		return (0);

	if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
		return (0);

	return (1);
}

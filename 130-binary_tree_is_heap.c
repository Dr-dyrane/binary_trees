#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The size of the binary tree, or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Calculate size of the binary tree recursively */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Checks if the binary tree is complete.
 * @tree: A pointer to the root node of the binary tree.
 * @index: The index of the current node.
 * @size: The total number of nodes in the binary tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int tree_is_complete(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);

	if (i >= size)
		return (0);

	return (tree_is_complete(tree->left, (2 * index) + 1, size) &&
		tree_is_complete(tree->right, (2 * index) + 2, size));
}


/**
 * binary_tree_is_complete - calls to tree_is_complete function
 *
 * @tree: tree root
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, size));
}

/**
 * max_heap - Checks if the max heap property is satisfied.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the max heap property is satisfied, 0 otherwise.
 */
int max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (max_heap(tree->left) && max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max binary heap.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a max binary heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	/* Check if the tree is complete and satisfies the max heap property */
	if (!binary_tree_is_complete(tree))
		return (0);

	return (max_heap(tree->left) && max_heap(tree->right));
}

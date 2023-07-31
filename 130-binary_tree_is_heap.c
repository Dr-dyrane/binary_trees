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
 * is_complete - Checks if the binary tree is complete.
 * @tree: A pointer to the root node of the binary tree.
 * @index: The index of the current node.
 * @size: The total number of nodes in the binary tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int index, size_t size)
{
	if (tree == NULL)
		return (1);

	/* Check if the current node's index is within the total number of nodes */
	if (index >= size)
		return (0);

	/* Check recursively for left and right subtrees */
	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * is_heap_property_satisfied - Checks if the max heap property is satisfied.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the max heap property is satisfied, 0 otherwise.
 */
int is_heap_property_satisfied(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/* Check if the max heap property is satisfied for the current node */
	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	/* Check recursively for left and right subtrees */
	return (is_heap_property_satisfied(tree->left) &&
		is_heap_property_satisfied(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max binary heap.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a max binary heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	/* Calculate the total number of nodes in the binary tree */
	size = binary_tree_size(tree);

	/* Check if the tree is complete and satisfies the max heap property */
	if (!is_complete(tree, 0, size))
		return (0);

	return (is_heap_property_satisfied(tree));
}

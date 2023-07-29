#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: A pointer to the sibling node, or NULL if no sibling found.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the node is NULL or if it has no parent (root). */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Determine if the node is the left or right child of its parent. */
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: A pointer to the uncle node, or NULL if no uncle found.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	/* Check if the node is NULL or if it has no parent (root). */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Get the parent and grandparent of the node. */
	parent = node->parent;
	grandparent = parent->parent;

	/* If the node's parent has no parent, there is no uncle. */
	if (grandparent == NULL)
		return (NULL);

	/* Use the binary_tree_sibling function to find the uncle. */
	return (binary_tree_sibling(parent));
}

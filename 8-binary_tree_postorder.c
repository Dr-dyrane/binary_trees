#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a post-order traversal on a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to a function to call for each node's value.
 *
 * Description: In post-order traversal, the left subtree is traversed first,
 * then the right subtree is traversed, & finally, the current node is visited.
 * The `func` function is called for each node's value in this order.
 *
 * Return: If `tree` is NULL or `func` is NULL, does nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void(*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Visit the current node */
	func(tree->n);
}

#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to a function to call for each node's value.
 *
 * Description: In in-order traversal, the left subtree is traversed first,
 * then the current node is visited, and finally, the right subtree is
 * traversed. The `func` function is called for each node: value in this order.
 *
 * Return: If `tree` is NULL or `func` is NULL, does nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void(*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Traverse the left subtree */
	binary_tree_inorder(tree->left, func);

	/* Visit the current node */
	func(tree->n);

	/* Traverse the right subtree */
	binary_tree_inorder(tree->right, func);
}

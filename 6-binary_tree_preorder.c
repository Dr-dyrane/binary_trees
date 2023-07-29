#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal on a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to a function to call for each node's value.
 *
 * Description: In pre-order traversal, the current node is visited first,
 * then the left subtree is traversed, and finally the right subtree is
 * traversed. The `func` function is called for each node: value in this order.
 *
 * Return: If `tree` is NULL or `func` is NULL, does nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void(*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Visit the current node */
	func(tree->n);

	/* Traverse the left subtree */
	binary_tree_preorder(tree->left, func);

	/* Traverse the right subtree */
	binary_tree_preorder(tree->right, func);
}

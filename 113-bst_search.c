#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST.
 * @value: The value to search for in the BST.
 *
 * Return: A pointer to the node containing the matched value,
 * or NULL if not found.
 *
 * Description: This function searches for a specific value in a BST.
 *             It starts from the root node and traverses down the tree
 *             based on the value being searched,
 *             going left if the value is smaller
 *             than the current node, and right if it is greater.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* Base case: If the tree is empty or the current node matches the value. */
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	/* If the value is < the current node's value, search in the left subtree. */
	if (value < tree->n)
		return (bst_search(tree->left, value));
	/* If the value is > the current node's value, search in the right subtree. */
	else
		return (bst_search(tree->right, value));
}

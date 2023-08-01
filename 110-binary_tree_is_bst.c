#include "binary_trees.h"
/**
 * find_node - Finds a node in a binary search tree.
 * @root: The root of the tree to search.
 * @node: The node to find.
 *
 * Return: 1 if the node is found, 0 otherwise.
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);

	if (node == root)
		return (1);

	if (node->n < root->n)
		return (find_node(root->left, node));

	if (node->n > root->n)
		return (find_node(root->right, node));

	return (0);
}
/**
 * is_bst_recursive - Checks if a binary tree is a binary search tree.
 * @root: The root node of the binary tree.
 * @node: The current node being evaluated.
 *
 * Return: 1 if the tree is a binary search tree, 0 otherwise.
 */
int is_bst_recursive(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int new_root = 0;

		new_root = find_node(root, node);
		if (node->left)
			new_root &= is_bst_recursive(root, node->left);
		if (node->right)
			new_root &= is_bst_recursive(root, node->right);
		return (new_root);
	}
	return (0);
}
/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 *
 * Description: This function checks if the binary tree is a
 * valid Binary Search Tree.
 *             A Binary Search Tree (BST) is a binary tree where for each node:
 *             - The left subtree contains only nodes with values less
 *             than the node's value.
 *             - The right subtree contains only nodes with values greater
 *             than the node's value.
 *             - Both the left and right subtrees are also BSTs.
 *             This implementation uses in-order traversal to validate the BST.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_recursive((binary_tree_t *)tree, (binary_tree_t *)tree));
}

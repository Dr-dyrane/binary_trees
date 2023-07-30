#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: A pointer to the new root node of the rotated tree.
 *
 * Description: This function performs a left rotation on the binary tree.
 *             The left rotation is done in such a way that the right child
 *             of the current root becomes the new root, and the old root
 *             becomes the left child of the new root.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	/* Check if the tree is NULL or if it doesn't have a right child. */
	if (tree == NULL || tree->right == NULL)
		return (tree);

	/* Store the new root (right child of the current root). */
	binary_tree_t *new_root = tree->right;

	/* Update the right child of the current root. */
	tree->right = new_root->left;

	/* Update the parent of the new right child (if it exists). */
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Update the left child of the new root (old root). */
	new_root->left = tree;

	/* Update the parent of the new root (old parent of the current root). */
	new_root->parent = tree->parent;

	/* Update the parent of the current root (now it's the new root). */
	tree->parent = new_root;

	/* Return the new root of the rotated tree. */
	return (new_root);
}

#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: A pointer to the new root node of the rotated tree.
 *
 * Description: This function performs a right rotation on the binary tree.
 *             The right rotation is done in such a way that the left child
 *             of the current root becomes the new root, and the old root
 *             becomes the right child of the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	/**
	 *  Check if the tree or its left child is NULL.
	 *  If so, no rotation is possible.
	 */
	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Store the left child as the new root of the tree. */
	binary_tree_t *new_root = tree->left;

	/**
	 * Update the left child of the current root to be
	 * the right child of the new root.
	 */
	tree->left = new_root->right;

	/**
	 * Update the parent of the right child of
	 * the new root to be the current root.
	 */
	if (new_root->right != NULL)
		new_root->right->parent = tree;

	/* Make the old root the right child of the new root. */
	new_root->right = tree;

	/* Update the parent of the current root to be the new root. */
	new_root->parent = tree->parent;

	/**
	 * Update the parent of the new root to be NULL,
	 * as it becomes the new root of the subtree.
	 */
	tree->parent = new_root;

	/* Return the new root of the rotated tree. */
	return (new_root);
}

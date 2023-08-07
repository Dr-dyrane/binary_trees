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
	binary_tree_t *new_root, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		temp = tree->left->right;
		new_root = tree->left;
		new_root->parent = tree->parent;
		new_root->right = tree;
		tree->parent = new_root;
		tree->left = temp;
		if (temp)
			temp->parent = tree;
		return (new_root);
	}
	return (NULL);
}

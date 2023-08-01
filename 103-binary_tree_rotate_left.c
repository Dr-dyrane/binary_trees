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
	binary_tree_t *new_root, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temp = tree->right->left;
		new_root = tree->right;
		new_root->parent = tree->parent;
		new_root->left = tree;
		tree->parent = new_root;
		tree->right = temp;
		if (temp)
			temp->parent = tree;
		return (new_root);
	}
	return (NULL);
}

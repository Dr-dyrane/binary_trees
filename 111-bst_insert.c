#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to insert into the BST.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 *
 * Description: This function inserts a new node containing the given
 * value into the BST.
 *             If the tree is empty, the new node becomes the root.
 *             If the value already exists in the BST,
 *             the function does nothing.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	/* If the tree is empty, create a new node and make it the root. */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* If the value is < the current node, insert it in the left subtree. */
	if (value < (*tree)->n)
	{
		/* Recursively call bst_insert on the left subtree. */
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (bst_insert(&((*tree)->left), value));
		}
	}

	/* If the value is > the current node, insert it in the right subtree. */
	if (value > (*tree)->n)
	{
		/* Recursively call bst_insert on the right subtree. */
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			return (bst_insert(&((*tree)->right), value));
		}
	}

	/* If the value already exists in the tree, do nothing and return NULL. */
	return (NULL);
}

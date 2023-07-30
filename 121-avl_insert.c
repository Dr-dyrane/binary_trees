#include "binary_trees.h"

/**
 *height - Measures the height of a binary tree.
 *@tree: A pointer to the root node of the binary tree.
 *
 *Return: The height of the binary tree, or 0 if the tree is NULL.
 *
 *Description: This function calculates the height of the binary tree by
 *             recursively measuring the height of the left and right subtrees.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = height(tree->left);
	size_t right_height = height(tree->right);

	return (MAX(left_height, right_height) + 1);
}

/**
 *balance_factor - Calculates the balance factor of a binary tree.
 *@tree: A pointer to the root node of the binary tree.
 *
 *Return: The balance factor of the binary tree, or 0 if the tree is NULL.
 *
 *Description: The balance factor of a binary tree is defined as the difference
 *             between the height of the left subtree and
 *             the height of the right subtree.
 */
int balance_factor(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (left_height - right_height);
}

/**
 *avl_insert_recursive - Inserts a value into an AVL tree recursively.
 *@parent: The parent node of the current working node.
 *@node: A double pointer to store the new node.
 *@value: The value to insert.
 *
 *Return: A pointer to the inserted node, or NULL on failure.
 *
 *Description: This function inserts a new node with
 *             the given value into the AVL tree.
 *             It follows the standard binary search tree insertion logic and
 *             performs AVL tree rotations if necessary to maintain
 *             the AVL tree property.
 */
avl_t *avl_insert_recursive(avl_t *parent, avl_t **node, int value)
{
	if (*node == NULL)
	{
		/*Create a new node and return it. */
		*node = binary_tree_node(parent, value);
		return (*node);
	}
	/**
	 * If the value is less than the current node's value,
	 * insert into the left subtree.
	 */
	if (value < (*node)->n)
	{
		(*node)->left = avl_insert_recursive(*node, &((*node)->left), value);
		if (balance_factor(*node) > 1)
		{
			if (value < (*node)->left->n)
				return (binary_tree_rotate_right(*node));
			{
				(*node)->left = binary_tree_rotate_left((*node)->left);
				return (binary_tree_rotate_right(*node));
			}
		}
	}
	/* If the value > current node's value,insert into the right subtree.*/
	else if (value > (*node)->n)
	{
		(*node)->right = avl_insert_recursive(*node, &((*node)->right), value);
		if (balance_factor(*node) < -1)
		{
			if (value > (*node)->right->n)
				return (binary_tree_rotate_left(*node));
			{
				(*node)->right = binary_tree_rotate_right((*node)->right);
				return (binary_tree_rotate_left(*node));
			}
		}
	}
	return (*node);
}

/**
 *avl_insert - Inserts a value into an AVL tree.
 *@tree: A double pointer to the root node of the AVL tree to insert into.
 *@value: The value to insert.
 *
 *Return: A pointer to the inserted node, or NULL on failure.
 *
 *Description: This function inserts a new node with
 *             the given value into the AVL tree.
 *             It ensures that the AVL tree property
 *             is maintained after insertion.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	return (avl_insert_recursive(NULL, tree, value));
}

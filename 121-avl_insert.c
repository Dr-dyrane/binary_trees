#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance_factor(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

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
	if (tree != NULL)
	{
		size_t left_height = 0, r = 0;

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
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
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 *Return: A pointer to the inserted node, or NULL on failure.
 *
 *Description: This function inserts a new node with
 *             the given value into the AVL tree.
 *             It follows the standard binary search tree insertion logic and
 *             performs AVL tree rotations if necessary to maintain
 *             the AVL tree property.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int balance;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance = balance_factor(*tree);
	if (balance > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
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
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}

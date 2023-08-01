#include "binary_trees.h"

/**
 *binary_tree_height - Measures the height of a binary tree.
 *@tree: A pointer to the root node of the tree to measure the height.
 *
 *Return: If tree is NULL, the function returns 0. Otherwise, it returns
 *       the height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/*If the tree is NULL, return height as 0 */
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		/*Recursively calculate the height of the left subtree */
		if (tree->left)
			left_height = binary_tree_height(tree->left);

		/*Recursively calculate the height of the right subtree */
		if (tree->right)
			right_height = binary_tree_height(tree->right);

		/*Return the maximum height between the left and right subtrees */
		return (left_height > right_height ? left_height + 1 : right_height + 1);
	}

	/*If the tree is NULL, return 0 as specified in the requirements. */
	return (0);
}

/**
 *print_at_level - Prints nodes - specific level during level-order traversal.
 *@tree: A pointer to the root node of the tree.
 *@func: A pointer to a function to call for each node.
 *@level: The level to print nodes.
 */
void print_at_level(const binary_tree_t *tree, void(*func)(int), int level)
{
	/*Base case: If tree is NULL, do nothing */
	if (tree && func)
	{
		/*If we reach the desired level, call the function to print the node */
		if (level == 1)
			func(tree->n);
		else
		{ /*Recursively call print_at_level for left and right subtrees */
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}
}

/**
 *binary_tree_levelorder - Performs a level-order traversal of the binary tree.
 *@tree: A pointer to the root node of the tree to traverse.
 *@func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void(*func)(int))
{
	size_t height = 0, i = 1;

	if (tree && func)
	{
		/*Calculate the height of the binary tree */
		height = binary_tree_height(tree);

		/*Traverse each level and call print_at_level to print nodes */
		while (i <= height + 1)
		{
			print_at_level(tree, func, i);
			i++;
		}
	}
}

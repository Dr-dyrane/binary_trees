#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Base case: If tree is NULL, height is 0. */
	if (tree == NULL)
		return (0);

	/* Calculate the height of the left and right subtrees. */
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/* Return the height of the tree as the maximum height of subtrees + 1. */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * print_at_level - Prints nodes - specific level during level-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @func: A pointer to a function to call for each node.
 * @level: The level to print nodes.
 */
void print_at_level(const binary_tree_t *tree, void(*func)(int), int level)
{
	/* Base case: If tree is NULL, do nothing. */
	if (tree == NULL)
		return;

	/* If we reach the desired level, call the function to print the node. */
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		/* Recursively call print_at_level for left and right subtrees. */
		print_at_level(tree->left, func, level - 1);
		print_at_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Performs a level-order traversal - the binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void(*func)(int))
{
	/* Check if the tree or function is NULL (base case). */
	if (tree == NULL || func == NULL)
		return;

	/* Calculate the height of the binary tree. */
	size_t height = binary_tree_height(tree);

	/* Traverse each level and call print_at_level to print nodes. */
	for (int level = 1; level <= height; level++)
		print_at_level(tree, func, level);
}

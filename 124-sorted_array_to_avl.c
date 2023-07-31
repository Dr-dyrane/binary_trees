#include "binary_trees.h"

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree.
 * @array: A pointer to the first element of the sorted array.
 * @size: The size of the array.
 *
 * Return: A pointer to the root node of the AVL tree, or NULL on failure.
 *
 * Description: This function converts a sorted array to a balanced AVL tree.
 *             It uses a recursive approach to build the tree by selecting the
 *             middle element of the array as the root and creating the left
 *             and right subtrees recursively from the left and right halves
 *             of the array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	size_t mid = size / 2;

	/* Create the root node using the middle element of the array. */
	avl_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	/* Recursively create the left subtree using the left half of the array. */
	root->left = sorted_array_to_avl(array, mid);

	/* Recursively create the right subtree using the right half of the array. */
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	return (root);
}

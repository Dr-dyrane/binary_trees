#include "binary_trees.h"

/**
 * array_to_bst - Converts an array of integers to a Binary Search Tree (BST).
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 *
 * Description: This function creates a balanced BST from
 * a sorted array of integers.
 *             It uses the bst_insert function to insert elements into the BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	/* Check if the array is empty or NULL. */
	if (array == NULL || size == 0)
		return (NULL);

	/* Insert each element from the array into the BST. */
	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	return (tree);
}

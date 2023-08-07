#include "binary_trees.h"

/**
 * count_h_nodes - Counts the number of nodes in a binary tree.
 * @root: Pointer to the root node of the binary tree.
 *
 * Return: Number of nodes in the binary tree.
 */
int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to
 * a sorted array of integers.
 * @heap: A pointer to the root node of the Binary Max Heap.
 * @size: The address to store the size of the array.
 *
 * Return: A pointer to the newly created sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, count, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	count = count_h_nodes(heap);
	arr = malloc(sizeof(*arr) * count);
	if (!arr)
		return (NULL);

	*size = count;
	for (i = 0; i < count; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}

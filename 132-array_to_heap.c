#include "binary_trees.h"

/**
 * array_to_heap - Converts an array to a max binary heap.
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
 *
 * Return: A pointer to the root node of the max binary heap,
 *        or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	/* Initialize the root of the max binary heap as NULL */
	heap_t *root = NULL;
	size_t i;

	/* Check if the input array is NULL or empty */
	if (array == NULL || size == 0)
		return (NULL);

	/* Iterate through the array & insert each element into -  max binary heap */
	for (i = 0; i < size; i++)
	{
		/* Use the heap_insert function to insert the current element into - heap */
		heap_insert(&root, array[i]);
	}

	/* Return a pointer to the root node of the max binary heap */
	return (root);
}

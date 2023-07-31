#include "binary_trees.h"

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
	int *sorted_array;
	size_t count = 0, i;

	if (heap == NULL || size == NULL)
		return (NULL);

	/* Count the number of nodes in the heap */
	count = binary_tree_size(heap);

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * count);

	if (sorted_array == NULL)
		return (NULL);

	/* Extract elements from the heap and store them in the sorted array */
	for (i = 0; i < count; i++)
	{
		/* Store the extracted element in reverse order for descending sorting */
		sorted_array[count - 1 - i] = heap_extract(&heap);
	}

	/* Set the size of the array and return the sorted array */
	*size = count;
	return (sorted_array);
}

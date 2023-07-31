/**
 * array_to_avl - Converts an array to an AVL tree.
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
 *
 * Return: A pointer to the root node of the AVL tree, or NULL on failure.
 *
 * Description: This function converts an array to an AVL tree by inserting
 *             each element of the array into the AVL tree using the
 *             avl_insert function.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	/* Check for valid inputs */
	if (array == NULL || size == 0)
		return (NULL);

	/* Initialize a pointer to the root node of the AVL tree */
	avl_t *root = NULL;

	/* Loop through each element in the array */
	for (size_t i = 0; i < size; i++)
	{
		/* Insert the current element into the AVL tree */
		if (avl_insert(&root, array[i]) == NULL)
			return (NULL);
	}

	/* Return the root node of the resulting AVL tree */
	return (root);
}

#include "binary_trees.h"

/**
 * create_avl_tree - Creates an AVL tree using elements from a sorted array.
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @begin: Position where the array starts.
 * @last: Position where the array ends.
 *
 * Return: A pointer to the root of the AVL tree, or NULL on failure.
 */
avl_t *create_avl_tree(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *new_node;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		new_node = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (new_node == NULL)
			return (NULL);

		root = (avl_t *)new_node;
		root->left = create_avl_tree(root, array, begin, mid - 1);
		root->right = create_avl_tree(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 * @array: Sorted array.
 * @size: Size of the sorted array.
 *
 * Return: A pointer to the root of the AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (create_avl_tree(NULL, array, 0, ((int)(size)) - 1));
}

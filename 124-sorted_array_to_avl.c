#include "binary_trees.h"
/**
 * create_avl_tree - Create the AVL tree using the half element of the array.
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @begin: Position where the array starts.
 * @last: Position where the array ends.
 *
 * Return: The AVL tree root node, or NULL on failure.
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
	return (create_avl_tree(NULL, array, 0, ((int)(size)) - 1));
}

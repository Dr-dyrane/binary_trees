#include "binary_trees.h"

/**
 *count_nodes - Counts the number of nodes in a binary tree.
 *@root: Pointer to the root node of the tree.
 *
 *Return: Number of nodes in the tree.
 */
int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 *bubble_down - Bubbles down a node's value to maintain the max heap property.
 *@parent: Pointer to the parent node in the heap.
 */
void bubble_down(heap_t *parent)
{
	int temp;
	heap_t *max_child = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		/*Find the maximum child among left and right child */
		max_child = parent->left;
		if (parent->right && parent->right->n > parent->left->n)
			max_child = parent->right;

		/*Swap the parent with the maximum child if necessary */
		if (max_child->n > parent->n)
		{
			temp = parent->n;
			parent->n = max_child->n;
			max_child->n = temp;
		}

		parent = max_child;
	}
}

/**
 *get_parent - Finds the parent node of a certain node in the heap.
 *@root: Pointer to the root node of the heap.
 *@index: Index of the current node.
 *@target_index: Index being searched for.
 *
 *Return: Pointer to the parent node.
 */
heap_t *get_parent(heap_t *root, int index, int target_index)
{
	heap_t *left = NULL, *right = NULL;

	if (!root || index > target_index)
		return (NULL);

	if (index == target_index)
		return (root);

	left = get_parent(root->left, index * 2 + 1, target_index);
	if (left)
		return (left);

	right = get_parent(root->right, index * 2 + 2, target_index);
	if (right)
		return (right);

	return (NULL);
}

/**
 *remove_last_node - Removes the last node from the max heap.
 *@root: Double pointer to the root node of the heap.
 *@parent: Pointer to the parent node from which to remove the last node.
 */
void remove_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;
		return;
	}

	if (parent->right)
	{
		/*Replace the root node with the right child and remove the right child */
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		/*Replace the root node with the left child and remove the left child */
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	/*Rebalance the heap after removing the node */
	bubble_down(*root);
}

/**
 *heap_extract - Extracts the root node from a max binary heap.
 *@root: Double pointer to the root node of the binary heap.
 *
 *Return: The value of the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int num_nodes, target_index = 0, max_value = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	/*Get the maximum value from the root node */
	max_value = (*root)->n;

	/**
	 * Count the number of nodes in the heap and
	 * find the index of the parent of the last node
	 */
	num_nodes = count_nodes(*root);
	target_index = (num_nodes - 2) / 2;
	parent = get_parent(*root, 0, target_index);

	/*Remove the last node and rebalance the heap */
	remove_last_node(root, parent);

	return (max_value);
}

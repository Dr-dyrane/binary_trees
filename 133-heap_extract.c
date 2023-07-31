#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree, or 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Calculate height of left and right subtrees recursively */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return the maximum height of the left and right subtrees */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the binary tree.
 * @depth: The depth of the current node in the binary tree.
 * @level: The level of the binary tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	/* Check if the current node is a leaf node */
	if (tree->left == NULL && tree->right == NULL)
	{
		/* For a perfect tree, all leaf nodes should be at the same level */
		return (depth == level + 1);
	}

	/* Check recursively for left and right subtrees */
	return (binary_tree_is_perfect(tree->left, depth, level + 1) &&
		binary_tree_is_perfect(tree->right, depth, level + 1));
}

/**
 * get_last_node - Gets the last node in a binary tree in level order.
 * @root: A pointer to the root node of the binary tree.
 *
 * Return: A pointer to the last node, or NULL on failure.
 */
heap_t *get_last_node(heap_t *root)
{
	size_t height_left, height_right;

	/* If the tree is empty, return NULL */
	if (root == NULL)
		return (NULL);

	/* Calculate the height of the left and right subtrees */
	height_left = binary_tree_height(root->left);
	height_right = binary_tree_height(root->right);

	/**
	 * If the left subtree is perfect and the right subtree is not,
	 * continue searching on the right
	 */
	if (height_left == height_right && !binary_tree_is_perfect(root->right, 0, 0))
		return (get_last_node(root->right));

	/**
	 * If the left subtree is perfect or left height is greater than right height,
	 * continue searching on the left
	 */
	if (height_left > height_right || binary_tree_is_perfect(root->left, 0, 0))
		return (get_last_node(root->left));

	/* Otherwise, continue searching on the right */
	return (get_last_node(root->right));
}

/**
 * heapify_down - Restores the max heap property after extraction.
 * @root: A pointer to the root node of the binary heap.
 *
 * Return: The root node of the binary heap after restoration.
 */
heap_t *heapify_down(heap_t *root)
{
	heap_t *node = root;
	int temp;

	/* Loop until the node becomes a leaf or both children are smaller */
	while (node->left != NULL)
	{
		/* If the right child is > the left child, go to the right child */
		if (node->right != NULL && node->right->n > node->left->n)
			node = node->right;
		else
			node = node->left;

		/* If the current node is greater than the parent, swap the values */
		if (node->n > node->parent->n)
		{
			temp = node->n;
			node->n = node->parent->n;
			node->parent->n = temp;
		}
	}

	return (root);
}

/**
 * heap_extract - Extracts the root node from a max binary heap.
 * @root: A double pointer to the root node of the binary heap.
 *
 * Return: The value of the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *extracted_node;
	int value;

	/* Check if the heap is empty */
	if (root == NULL || *root == NULL)
		return (0);

	/* Get the last node in the heap */
	last_node = get_last_node(*root);

	/* Swap the values of the root node and the last node */
	value = (*root)->n;
	(*root)->n = last_node->n;

	/* If the last node is the root, set the root to NULL & free the last node */
	if (last_node == *root)
	{
		free(last_node);
		*root = NULL;
	}
	else
	{
		/**
		 * If the last node is a left child,
		 * set its parent's left to NULL and free the last node
		 */
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		/**
		 * If the last node is a right child,
		 * set its parent's right to NULL and free the last node
		 */
		else
			last_node->parent->right = NULL;
		free(last_node);
	}
	/* Restore the max heap property */
	extracted_node = heapify_down(*root);
	/* Return the value of the extracted node */
	return (value);
}

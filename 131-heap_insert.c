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
 * swap_nodes - Swaps nodes when child is greater than parent.
 * @node: The node to start swapping.
 *
 * Return: The new parent node after swapping.
 */
heap_t *swap_nodes(heap_t *node)
{
	int temp;
	heap_t *parent = node->parent;

	while (parent && node->n > parent->n)
	{
		temp = node->n;
		node->n = parent->n;
		parent->n = temp;

		node = parent;
		parent = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a max binary heap.
 * @root: A double pointer to the root node of the binary heap.
 * @value: The value to insert.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	/* If the binary heap is empty, create the root node */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	/* Find the first available node for insertion based on level order */
	parent = *root;
	while (parent)
	{
		/* If the left child is NULL, insert the new node here */
		if (parent->left == NULL)
		{
			parent->left = binary_tree_node(parent, value);
			new_node = parent->left;
		}

		/* If the right child is NULL, insert the new node here */
		else if (parent->right == NULL)
		{
			parent->right = binary_tree_node(parent, value);
			new_node = parent->right;
		}

		/* Move to the next parent in level order traversal */
		else
		{
			parent = binary_tree_is_perfect(*root, 0, 0) ?
				parent->left : parent->right;
			continue;
		}
		/* Fix the max heap property by swapping nodes if necessary */
		new_node = swap_nodes(new_node);

		/* Return the newly inserted node */
		return (new_node);
	}
	return (NULL);
}

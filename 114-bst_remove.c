#include "binary_trees.h"

bst_t *find_inorder_successor(bst_t *root);
bst_t *bst_remove_node(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * find_inorder_successor - Finds the in-order successor of a node in a BST.
 * @root: A pointer to the root node of the BST.
 *
 * Return: A pointer to the in-order successor node.
 */
bst_t *find_inorder_successor(bst_t *root)
{
	/* Traverse left child till the leftmost node is found(in-order successor). */
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove_node - Deletes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the BST.
 * @node: The node to be deleted from the BST.
 *
 * Return: A pointer to the new root of the BST after deletion.
 *
 * Description: This function removes a node from the BST
 * and maintains the BST structure.
 *             If the node has no children, it is simply removed from the tree.
 *             If the node has one child, it is replaced by its child.
 *             If the node has two children,
 *             it is replaced by its in-order successor.
 */
bst_t *bst_remove_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* If node has no left child, replace with right child. */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* If node has no right child, replace with left child. */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* If node has two children:replace with in-order successor. */
	successor = find_inorder_successor(node->right);
	node->n = successor->n;

	return (bst_remove_node(root, successor));
}

/**
 * bst_remove_recursive - Helper function to remove
 * a node from a BST recursively.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the new root of the BST after removal.
 *
 * Description: This function is called recursively to remove
 * a node from the BST.
 *             It follows the BST property and maintains
 *             the BST structure after removal.
 *             If a node with the given value is found,
 *             it removes it using bst_remove_node.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_remove_node(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed from the BST.
 *
 * Return: A pointer to the new root of the BST after removal.
 *
 * Description: This function removes a node with
 * the specified value from the BST.
 *             - It follows the BST property and maintains
 *             the BST structure after removal.
 *             - If a node with the given value is found,
 *             it removes it and rebalances the tree.
 *             - If no node with the given value is found,
 *             the function returns NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	/* Call the helper function to remove the node from the BST. */
	return (bst_remove_recursive(root, root, value));
}

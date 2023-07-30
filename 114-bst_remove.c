#include "binary_trees.h"

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
	if (root == NULL)
		return (NULL);

	/* Search for the node to be deleted. */
	if (node->n < root->n)
		root->left = bst_remove_node(root->left, node);
	else if (node->n > root->n)
		root->right = bst_remove_node(root->right, node);
	else
	{
		/* Node found for deletion. */

		/* If node has no left child, replace with right child. */
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}

		/* If node has no right child, replace with left child. */
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		/* If node has two children:replace with in-order successor. */
		bst_t *temp = find_inorder_successor(root->right);

		root->n = temp->n;
		root->right = bst_remove_node(root->right, temp);
	}

	return (root);
}

/**
 * bst_remove_recursive - Helper function to remove
 * a node from a BST recursively.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
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
bst_t *bst_remove_recursive(bst_t *root, bst_t *node)
{
	if (root == NULL)
		return (NULL);

	/**
	 *  Search for the node to be deleted
	 *  in the left or right subtree.
	 */
	if (node->n < root->n)
		root->left = bst_remove_recursive(root->left, node);
	else if (node->n > root->n)
		root->right = bst_remove_recursive(root->right, node);
	else
		root = bst_remove_node(root, node);

	return (root);
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
	/* Search for the node with the given value in the BST. */
	bst_t *node = bst_search(root, value);

	if (node == NULL)
	{
		/* If node with the given value is not found, return NULL. */
		return (NULL);
	}

	/* Call the helper function to remove the node from the BST. */
	return (bst_remove_recursive(root, node));
}

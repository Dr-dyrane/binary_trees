#include "binary_trees.h"

/**
 * balance_avl - Balances an AVL tree.
 * @tree: A double pointer to the AVL tree.
 *
 * Description: This function balances the AVL tree rooted at 'tree'
 *             by performing AVL rotations if necessary.
 */
void balance_avl(avl_t **tree)
{
	int balance;

	if (tree == NULL || *tree == NULL)
		return;

	/* Recursively balance the left and right subtrees */
	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	/* Calculate the balance factor of the current node */
	balance = binary_tree_balance((const binary_tree_t *)*tree);

	/* Perform AVL rotations based on the balance factor */
	if (balance > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Finds the next successor node in the AVL tree.
 * @node: The current node in the AVL tree.
 * Return: The minimum value of this subtree.
 *
 * Description: This function finds the next successor node in the AVL tree
 *             rooted at 'node' by traversing to the leftmost node in the
 *             right subtree.
 */
int get_successor(avl_t *node)
{
	int left_val = 0;

	if (node == NULL)
		return (0);

	/* Find the leftmost node in the right subtree */
	left_val = get_successor(node->left);

	/* Return the minimum value of this subtree */
	if (left_val == 0)
		return (node->n);
	return (left_val);
}

/**
 * remove_node - Removes a node from the AVL tree depending on its children.
 * @root: The current root of the AVL tree.
 * Return: 0 if it has no children or other value if it has.
 *
 * Description: This function removes the node with 'root' from the AVL tree
 *             depending on its children and rebalances the tree if needed.
 */
int remove_node(avl_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		/* Case 1: Node has no children */
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		/* Case 2: Node has one child */
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor(root->right);/* Case 3: Node has two children */
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Remove a node from a binary search tree (BST).
 * @root: The root of the BST.
 * @value: The value of the node to remove.
 * Return: The modified BST.
 *
 * Description: This function removes the node with 'value' from the BST rooted
 *             at 'root' and balances the tree if needed.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 *avl_remove - Remove a node from an AVL tree.
 *@root: The root of the AVL tree.
 *@value: The value of the node to remove.
 *Return: The modified AVL tree.
 *
 *Description: This function removes the node with 'value' from the AVL tree
 *             rooted at 'root' and rebalances the tree if needed.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	/* Remove node using the bst_remove function */
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);

	/* Rebalance the AVL tree */
	balance_avl(&root_a);
	return (root_a);
}

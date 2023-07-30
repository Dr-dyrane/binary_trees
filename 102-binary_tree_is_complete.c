#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *       Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * enqueue - Adds a node to the back of the queue.
 * @node: The binary tree node to add to the queue.
 * @rear: Pointer to the rear of the queue.
 *
 * Description: This function adds a new node to the back of the queue.
 *            It is used to perform a level-order traversal of the tree.
 */
void enqueue(const binary_tree_t *node, levelorder_queue_t **rear)
{
	levelorder_queue_t *new_node = create_node((binary_tree_t *)node);

	if (new_node == NULL)
		exit(1); /*Error handling: Exit if malloc fails. */

	if (*rear == NULL)
		*rear = new_node;
	else
	{
		(*rear)->next = new_node;
		*rear = new_node;
	}
}

/**
 * dequeue - Removes the front node from the queue.
 * @front: Pointer to the front of the queue.
 *
 * Description: This function removes the front node from the queue.
 *            It is used to perform a level-order traversal of the tree.
 */
void dequeue(levelorder_queue_t **front)
{
	levelorder_queue_t *temp = *front;

	*front = (*front)->next;
	free(temp);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 *
 * Description: This function checks if a binary tree is complete,
 *            i.e., all levels are filled except possibly the last,
 *            and the last level is filled from left to right.
 *            It uses a level-order traversal to perform the check.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	levelorder_queue_t *front = NULL, *rear = NULL;
	int flag = 0;

	enqueue(tree, &rear);

	while (front != NULL)
	{
		const binary_tree_t *current = front->node;

		if (current->left)
		{
			if (flag)
			{
				free_queue(front);
				return (0);
			}
			enqueue(current->left, &rear);
		}
		else
			flag = 1;

		if (current->right)
		{
			if (flag)
			{
				free_queue(front);
				return (0);
			}

			enqueue(current->right, &rear);
		}
		else
			flag = 1;

		dequeue(&front);
	}
	return (1);
}

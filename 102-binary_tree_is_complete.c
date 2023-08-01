#include "binary_trees.h"
#include <stdlib.h>

/**
 *create_node - Creates a new levelorder_queue_t node.
 *@node: The binary tree node for the new node to contain.
 *
 *Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));

	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 *free_queue - Frees a levelorder_queue_t queue.
 *@head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	while (head)
	{
		levelorder_queue_t *temp = head;

		head = head->next;
		free(temp);
	}
}

/**
 *enqueue - Pushes a node to the back of a levelorder_queue_t queue.
 *@node: The binary tree node to enqueue.
 *@head: A double pointer to the head of the queue.
 *@tail: A double pointer to the tail of the queue.
 *
 *Description: Upon malloc failure, exits with a status code of 1.
 */
void enqueue(binary_tree_t *node, levelorder_queue_t **head,
	levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node = create_node(node);

	if (!new_node)
	{
		free_queue(*head);
		exit(1);
	}

	if (*head == NULL)
		*head = new_node;
	else
		(*tail)->next = new_node;

	*tail = new_node;
}

/**
 *dequeue - Pops the head of a levelorder_queue_t queue.
 *@head: A double pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
	if (*head == NULL)
		return;

	levelorder_queue_t *temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 *binary_tree_is_complete - Checks if a binary tree is complete.
 *@tree: A pointer to the root node of the tree to traverse.
 *
 *Return: If the tree is NULL or not complete, 0. Otherwise, 1.
 *
 *Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	levelorder_queue_t *head = NULL, *tail = NULL;
	int flag = 0;

	enqueue((binary_tree_t *)tree, &head, &tail);

	while (head)
	{
		binary_tree_t *current = head->node;

		dequeue(&head);

		if (current->left)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			enqueue(current->left, &head, &tail);
		}
		else
			flag = 1;

		if (current->right)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}

			enqueue(current->right, &head, &tail);
		}
		else
			flag = 1;
	}
	return (1);
}

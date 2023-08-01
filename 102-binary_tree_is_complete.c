#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void dequeue(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

i	new_node = malloc(sizeof(levelorder_queue_t));
	if (!new_node)
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

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * enqueue - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and enqueue.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = create_node(node);
	if (!new_node)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * dequeue - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (!tree)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (!head)
		exit(1);

	while (head)
	{
		if (head->node->left)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			enqueue(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			enqueue(head->node->right, head, &tail);
		}
		else
			flag = 1;
		dequeue(&head);
	}
	return (1);
}

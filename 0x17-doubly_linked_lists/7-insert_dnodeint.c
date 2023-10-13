i#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: Pointer to a pointer to the head of the list
 * @idx: Index of the list where the new node should be added, starting from 0
 * @n: Value to be assigned to the new node's data (n)
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *new_node;
	dlistint_t *temp;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL || h == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *h;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	temp = *h;
	for ( ; i < idx - 1 && temp; i++)
	{
		temp = temp->next;
	}
	if (!temp)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = temp->next;
	new_node->prev = temp;

	if (temp->next)
		temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}

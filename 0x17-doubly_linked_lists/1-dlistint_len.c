#include "lists.h"


/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @h: pointer to the head of a doubly linked list (dlistint_t).
 *
 * Return: Number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t node_count = 0;
	const dlistint_t *current_node = h;

	while (current_node != NULL)
	{
		node_count++;
		current_node = current_node->next;
	}

	return (node_count);
}


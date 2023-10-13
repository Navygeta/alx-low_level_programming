#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t.
 * @head: Pointer to the head of the list.
 * @index: Index of the node, starting from 0.
 * Return: The nth node or NULL if non existent.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current_node = head;

	while (current_node != NULL && index > 0)
	{
		current_node = current_node->next;
		index--;
	}

	return (current_node);
}

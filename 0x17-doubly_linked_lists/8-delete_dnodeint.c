#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t.
 * @head: Double pointer to head node of list
 * @index: Node counter
 * Return: 1 on success and -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	delete_dnodeint_at_index *ptr = *head, *prev_node = NULL;

	if (ptr == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = ptr->next;
		free(ptr);
		return (1);
	}
	while (ptr != NULL && index > 0)
	{
		prev_node = ptr;
		ptr = ptr->next;
		index--;
	}
	if (ptr == NULL)
	{
		return (-1);
	}
	prev_node->next = ptr->next;
	if (ptr->next != NULL)
	{
		ptr->next->prev = prev_node;
	}
	free(ptr);
	return (1);
}

#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of listint_t
 * @head: first node in the listint_t
 * @index: index of the node to return
 *
 * Return: pointer to the nth node, or NULL on failure
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *temp = head;

	for (i = 0; temp && i < index; i++)
	{
		temp = temp->next;
	}

	return (temp ? temp : NULL);
}

#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a dlistint_t.
 * @head: Head of the list pointer.
 * Return: Sum of all data(n) or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;
	dlistint_t *current_node = head;

	while (current_node != NULL)
	{
		sum += current_node->n;
		current_node = current_node->next;
	}

	return (total);
}

#include "lists.h"

/**
 * listint_len - returns the number of elmnts in the linked list
 * @h: linked list of type listint_t
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	for (; h != NULL; h = h->next)
	{
		num++;
	}

	return (num);
}

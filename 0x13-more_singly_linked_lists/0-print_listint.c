#include "lists.h"

/**
 * print_listint - it prints all elements of the linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	for (;h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		num++;
	}

	return (num);
}

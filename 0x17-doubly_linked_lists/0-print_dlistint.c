#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: pointer to the head of a doubly linked list (dlistint_t).
 * Return: Number of nodes.
 */
size_t print_dlistint(const dlistint_t *h);
{
	size_t node_counter = 0;

	while (h != NULL)
	{
		print("&d\n", h->n);
		h = h->next;
		node_counter++;
	}
	return node_counter
}

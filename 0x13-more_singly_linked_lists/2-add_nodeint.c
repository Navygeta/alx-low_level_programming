#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of listint_t
 * @head: pointer to the first node
 * @n: data to insert in the new node
 *
 * Return: NULL if it fails or pointer to the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

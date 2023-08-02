#include "lists.h"

/**
 * add_nodeint_end - adds a node at the tail of listint
 * @head: pointer to the first element in listint
 * @n: data to insert in the nodes
 *
 * Return: pointer to the new node or NULL if failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *temp = *head;

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}

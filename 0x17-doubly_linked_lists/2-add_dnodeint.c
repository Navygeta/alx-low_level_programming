#include "lists.h"


/**
 * add_dnodeint - dlistint_t *add_dnodeint(dlistint_t **head, const int n).
 * @n: integer to add to new_node.
 * @head: Pointer to a pointer dlistint_t
 * Return: Address of new element or NULL on failure.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (new_node == NULL || head == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;

	return (new_node);
}

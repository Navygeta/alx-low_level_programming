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

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	dlistint_t *current_node;

	current_node = *head;

	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = new_node;
	new_node->prev = current_node;

	return (new_node);
}

#include "lists.h"

/**
 * reverse_listint - reverses listint_t
 * @head: pointer to first node in listint_t
 *
 * Return: pointer to first node in new rev list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *before = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = before;
		before = *head;
		*head = next;
	}

	*head = before;

	return (*head);
}

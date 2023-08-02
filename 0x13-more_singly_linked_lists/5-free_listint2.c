#include "lists.h"

/**
 * free_listint2 - frees listint_t
 * @head: pointer to the list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	for (; *head; *head = temp)
	{
		temp = (*head)->next;
		free(*head);
	}

	*head = NULL;
}

#include "lists.h"

/**
 * free_listint - frees a listint_t
 * @head: link list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	for (; head; head = temp)
	{
		temp = head->next;
		free(head);
	}
}

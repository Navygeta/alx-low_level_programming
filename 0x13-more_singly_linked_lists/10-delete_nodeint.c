#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in listint_t at a given index
 * @head: pointer to the first element in listint_t
 * @index: given index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tempo = *head;
	listint_t *curr = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tempo);
		return (1);
	}

	while (x < index - 1)
	{
		if (!tempo || !(tempo->next))
			return (-1);
		tempo = tempo->next;
		x++;
	}


	curr = temop->next;
	tempo->next = curr->next;
	free(curr);

	return (1);
}

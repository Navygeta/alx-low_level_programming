#include "lists.h"

/**
 * insert_nodeint_at_index - inserts new node in listint_t,
 * at a given position
 * @head: pointer to the first node in listint_t
 * @idx: index on which to add new node
 * @n: data to be inserted
 *
 * Return: pointer to new node, or NULL if failuer
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (temp && i < idx)
	{
		if (i == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}
	i++;
	}
	return (NULL);
}

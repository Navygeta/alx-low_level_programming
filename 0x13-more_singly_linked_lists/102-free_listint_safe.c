#include "lists.h"

/**
 * free_listint_safe - frees listint_t
 * @h: pointer to the first node in listint_t
 *
 * Return: elements in freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int diff;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	for (; *h; len++)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}
		else
		{
			free(*h);
			*h = NULL;
			break;
		}
	}

	*h = NULL;

	return (len);
}

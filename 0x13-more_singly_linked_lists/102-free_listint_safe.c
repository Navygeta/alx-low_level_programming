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
	int dif;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		dif = *h - (*h)->next;
		if (dif > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}

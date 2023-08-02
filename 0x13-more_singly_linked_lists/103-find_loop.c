#include "lists.h"

/**
 * find_listint_loop - finds the loop in listint_t
 * @head: head node in list to search for
 *
 * Return: node address where loop starts or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tort = head;
	listint_t *fst = head;

	if (!head)
		return (NULL);

	while (tort && fst && fst->next)
	{
		fst = fst->next->next;
		tort = tort->next;
		if (fst == tort)
		{
			tort = head;
			while (tort != fst)
			{
				tort = tort->next;
				fst = fst->next;
			}
			return (fst);
		}
	}

	return (NULL);
}

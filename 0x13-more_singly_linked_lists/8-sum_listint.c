#include "lists.h"

/**
 * sum_listint - returns sum of all the data in listint_t
 * @head: first node in listint_t
 *
 * Return: sum of data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	for (temp = head; temp; temp = temp->next)
	{
		sum += temp->n;
	}

	return (sum);
}

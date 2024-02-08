#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of integers
 *                 using the Linear search algorithm.
 *
 * @arr: Input array to search in.
 * @size: Size of the array.
 * @val: Value to search for.
 *
 * Return: The index of the first occurrence of @val in @arr,
 *         or -1 if @val is not present or if @arr is NULL.
 */
int linear_search(int *arr, size_t size, int val)
{
	size_t index;

	if (arr == NULL)
		return (-1);

	for (index = 0; index < size; index++)
	{
		printf("Value checked arr[%zu] = [%d]\n", index, arr[index]);
		if (val == arr[index])
			return (index);
	}
	return (-1);
}

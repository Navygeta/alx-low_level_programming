#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where @value is located, or -1 if @value is not present
 *         or if @array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, left, right, midpoint;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		midpoint = left + (right - left) / 2;

		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[right]);

		if (array[midpoint] == value)
			return (midpoint);
		if (array[midpoint] > value)
			right = midpoint - 1;
		else
			left = midpoint + 1;
	}

	return (-1);
}

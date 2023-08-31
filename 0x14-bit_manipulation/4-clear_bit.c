#include "main.h"

/**
 * clear_bit - sets value of a bit to 0 at a given index
 * @n: pointer to the value to be changed
 * @index: index of the bit to be set to 0
 *
 * Return: 1 for success, else -1 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

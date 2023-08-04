#include "main.h"

/**
 * flip_bits - number of bits you would need to flip
 * to get from one number to another
 * @n: number one
 * @m: number two
 *
 * Return: flipped result
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, track = 0;
	unsigned long int old;
	unsigned long int exclusive = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		old = exclusive >> j;
		if (old & 1)
			track++;
	}

	return (track);
}

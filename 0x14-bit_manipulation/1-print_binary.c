#include "main.h"

/**
 * print_binary - prints binary reprsntion of a num
 * @n: result to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int j, count = 0;
	unsigned long int old;

	for (j = 63; j >= 0; j--)
	{
		old = n >> j;

		if (old & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}

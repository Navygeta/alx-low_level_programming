#include "main.h"

/**
 * print_binary - prints binary reprsntion of an int
 * @n: result to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int index, flag = 0;
	unsigned long int temp;

	for (index = 63; index >= 0; index--)
	{
		temp = n >> index;

		if (temp & 1)
		{
			_putchar('1');
			flag++;
		}
		else if (flag)
			_putchar('0');
	}
	if (!flag)
		_putchar('0');
}

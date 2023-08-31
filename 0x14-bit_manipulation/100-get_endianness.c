#include "main.h"

/**
 * get_endianness - checks the endianness of a system
 * Return: 0 if big, 1 if little
 */
int get_endianness(void)
{
	unsigned int test_val = 1;
	char *byt_ptr = (char *) &test_val;

	return (*byt_ptr);
}

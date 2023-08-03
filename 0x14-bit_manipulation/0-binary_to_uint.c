#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to string of 0 and 1 chars
 *
 * Return: converted number or 0 if theres 1 one more chars
 */
unsigned int binary_to_uint(const char *b)
{
	if (b==NULL)
		return (0);

	char ch;
	unsigned int dec_val = 0;

	while ((ch = *b) != '\0')
	{
		if (ch != '0' && ch != '1')
			return (0);
		dec_val = 2 * dec_val + (ch - '0');
		b++;
	}

	return (dec_val);
}

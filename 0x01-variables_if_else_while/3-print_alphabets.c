#include <stdio.h>

/**
 * main - Prints the alphabet.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char low[26] = "abcdefghijklmnopqrstuvwxyz";
	char up[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	int j;

	for (i = 0; i < 26; i++)
	{
		putchar(alp[i]);
	}
	for (j = 0; j < 26; j++)
        {
                putchar(up[j]);
        }
	putchar('\n');
	return (0);
}

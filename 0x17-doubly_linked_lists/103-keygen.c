#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords.
 * @argc: Argument count to the program.
 * @argv: Argument passed to the program or inputs.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char pswd[7], *cdx;
	int len = strlen(argv[1]), i, temp;

	cdx = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (len ^ 59) & 63;
	pswd[0] = cdx[temp];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += argv[1][i];
	pswd[1] = cdx[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < len; i++)
		temp *= argv[1][i];
	pswd[2] = cdx[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	pswd[3] = cdx[rand() & 63];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += (argv[1][i] * argv[1][i]);
	pswd[4] = cdx[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	pswd[5] = cdx[(temp ^ 229) & 63];

	pswd[6] = '\0';
	printf("%s", pswd);
	return (0);
}

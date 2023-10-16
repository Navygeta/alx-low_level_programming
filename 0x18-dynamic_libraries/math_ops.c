#include <stdio.h>
#include <unistd.h>

/**
 * add - Adds two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Sum of the two integers.
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtracts two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Result of the subtraction.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiplies two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Result of the multiplication.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * divide - Divides two integers.
 * @a: Dividend.
 * @b: Divisor.
 *
 * Return: Result of the division.
 */
int divide(int a, int b)
{
	if (b != 0)
		return (a / b);
	{
		write(2, "Error: Division by zero\n", 25);
		return (0);
	}
}

/**
 * mod - Computes the modulus of two integers.
 * @a: Dividend.
 * @b: Divisor.
 *
 * Return: Result of the modulus.
 */
int mod(int a, int b)
{
	if (b != 0)
		return (a % b);
	{
		write(2, "Error: Modulus by zero\n", 24);
		return (0);
	}
}

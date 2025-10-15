#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = '0';

	/* Print digits 0-9 */
	while (c <= '9')
	{
		putchar(c);
		c++;
	}

	c = 'a';  /* Reset for hex letters */

	/* Print letters a-f */
	while (c <= 'f')
	{
		putchar(c);
		c++;
	}

	putchar('\n');

	return (0);
}

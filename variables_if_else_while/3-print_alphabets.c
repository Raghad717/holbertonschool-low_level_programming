#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Print lowercase alphabet */
	letter = 'a';
	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}

	/* Print uppercase alphabet */
	letter = 'A';
	while (letter <= 'Z')
	{
		putchar(letter);
		letter++;
	}

	putchar('\n');

	return (0);
}

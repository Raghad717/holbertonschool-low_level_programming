#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0;
	int i, start;

	/* Find the length of the string */
	while (str[length] != '\0')
		length++;

	/* Calculate starting index for second half */
	if (length % 2 == 0)
		start = length / 2;
	else
		start = (length + 1) / 2;

	/* Print from start to end */
	for (i = start; i < length; i++)
		_putchar(str[i]);

	_putchar('\n');
}

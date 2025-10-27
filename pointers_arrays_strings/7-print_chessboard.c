#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: 2D array representing the chessboard
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int i;
	char *ptr;

	for (i = 0; i < 8; i++)
	{
		ptr = a[i];
		while (*ptr != '\0')
		{
			_putchar(*ptr);
			ptr++;
		}
		_putchar('\n');
	}
}


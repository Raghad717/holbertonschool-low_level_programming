#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer
 * @b: Buffer to print
 * @size: Size of buffer
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = i; j < i + 10; j += 2)
		{
			if (j < size)
				printf("%02x", b[j]);
			else
				printf("  ");

			if (j + 1 < size)
				printf("%02x ", b[j + 1]);
			else if (j + 1 < i + 10)
				printf("   ");
			else
				printf(" ");
		}

		for (j = i; j < i + 10; j++)
		{
			if (j >= size)
				break;

			if (b[j] >= 32 && b[j] <= 126)
				printf("%c", b[j]);
			else
				printf(".");
		}
		printf("\n");
	}
}

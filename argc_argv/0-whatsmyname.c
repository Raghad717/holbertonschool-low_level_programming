#include <stdio.h>

/**
 * main - prints the program name
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc; /* Unused parameter */

	printf("%s\n", argv[0]);

	return (0);
}


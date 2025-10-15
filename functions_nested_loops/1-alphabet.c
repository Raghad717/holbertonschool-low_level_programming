#include <unistd.h>

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Return: void
 */
void print_alphabet(void)
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
	write(1, "\n", 1);
}

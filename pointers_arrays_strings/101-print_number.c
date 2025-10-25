#include "main.h"

/**
 * print_number - prints an integer using only _putchar
 * @n: integer to print
 */
void print_number(int n)
{
	unsigned int num, divisor, digit;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	divisor = 1;
	while (num / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		_putchar(digit + '0');
		num %= divisor;
		divisor /= 10;
	}
}


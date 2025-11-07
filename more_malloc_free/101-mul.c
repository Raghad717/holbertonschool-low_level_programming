#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * is_digit - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if all are digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (s == NULL || s[0] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_error - Prints "Error" and exits with status 98
 */
void print_error(void)
{
	char error[] = "Error\n";
	int i = 0;

	while (error[i] != '\0')
	{
		_putchar(error[i]);
		i++;
	}
	exit(98);
}

/**
 * remove_leading_zeros - Removes leading zeros from a number string
 * @num: The number string to process
 *
 * Return: Pointer to the first non-zero digit
 */
char *remove_leading_zeros(char *num)
{
	while (*num == '0' && *(num + 1) != '\0')
		num++;
	return (num);
}

/**
 * multiply_strings - Multiplies two positive number strings and prints result
 * @num1: The first number as string
 * @num2: The second number as string
 */
void multiply_strings(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int total_len = len1 + len2;
	int *result;
	int i, j, carry, start = 0;
	int digit1, digit2, product;

	/* Handle multiplication by zero efficiently */
	if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0'))
	{
		_putchar('0');
		_putchar('\n');
		return;
	}

	result = malloc(total_len * sizeof(int));
	if (result == NULL)
		print_error();

	/* Initialize result array to zeros */
	for (i = 0; i < total_len; i++)
		result[i] = 0;

	/* Perform multiplication */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			product = digit1 * digit2 + result[i + j + 1] + carry;
			result[i + j + 1] = product % 10;
			carry = product / 10;
		}
		result[i] += carry;
	}

	/* Find first non-zero digit */
	while (start < total_len && result[start] == 0)
		start++;

	/* Print result */
	if (start == total_len)
	{
		_putchar('0');
	}
	else
	{
		for (i = start; i < total_len; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');

	free(result);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;

	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	num1 = remove_leading_zeros(argv[1]);
	num2 = remove_leading_zeros(argv[2]);

	multiply_strings(num1, num2);

	return (0);
}

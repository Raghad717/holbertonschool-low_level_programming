#include "main.h"

/**
 * check_palindrome - helper function to check palindrome
 * @s: string to check
 * @i: current position from start
 * @len: length of string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int i, int len)
{
	if (i >= len / 2)
		return (1);

	if (s[i] != s[len - 1 - i])
		return (0);

	return (check_palindrome(s, i + 1, len));
}

/**
 * _strlen_recursion - returns string length
 * @s: string to measure
 *
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (check_palindrome(s, 0, len));
}


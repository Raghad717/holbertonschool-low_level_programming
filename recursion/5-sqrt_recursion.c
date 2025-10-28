#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find square root of
 *
 * Return: natural square root of n, or -1 if not found
 */
int _sqrt_recursion(int n)
{
	return (sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - helper function for binary search
 * @n: number
 * @i: current guess
 * @limit: upper limit
 *
 * Return: square root or -1
 */
int sqrt_helper(int n, int i, int limit)
{
	if (i > limit)
		return (-1);

	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (sqrt_helper(n, i + 1, limit));
}


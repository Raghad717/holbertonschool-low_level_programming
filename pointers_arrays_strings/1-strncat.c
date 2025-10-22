#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string
 * @src: source string to append
 * @n: maximum number of bytes to use from src
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;
	int i = 0;

	/* Move to the end of dest string */
	while (*ptr != '\0')
		ptr++;

	/* Copy at most n bytes from src to dest */
	while (i < n && src[i] != '\0')
	{
		*ptr = src[i];
		ptr++;
		i++;
	}

	/* Add terminating null byte */
	*ptr = '\0';

	return (dest);
}

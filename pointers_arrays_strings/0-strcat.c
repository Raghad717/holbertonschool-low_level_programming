#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string to append
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* Find the end of dest */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Append src to dest */
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	/* Add null terminator */
	dest[i + j] = '\0';

	return (dest);
}

#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to the string to search
 * @accept: pointer to the string containing accepted characters
 *
 * Return: number of bytes in initial segment of s with only accept chars
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}

		if (accept[j] == '\0')
			return (i);
	}

	return (i);
}


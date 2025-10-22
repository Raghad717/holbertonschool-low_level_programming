#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *str)
{
	char *ptr = str;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";
	int i, j;

	while (*ptr != '\0')
	{
		for (i = 0; letters[i] != '\0'; i++)
		{
			if (*ptr == letters[i])
			{
				*ptr = numbers[i];
				break;
			}
		}
		ptr++;
	}
	return (str);
}

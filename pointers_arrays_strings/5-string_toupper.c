#include "main.h"

/**
 * string_toupper - changes all lowercase letters to uppercase
 * @str: string to convert
 *
 * Return: pointer to the converted string
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr = *ptr - 32;
		ptr++;
	}
	return (str);
}

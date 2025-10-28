#include "main.h"

/**
 * wildcmp - compares two strings with wildcard pattern matching
 * @s1: first string
 * @s2: second string (can contain '*')
 *
 * Return: 1 if strings match, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Both strings ended */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* s2 has '*' - handle wildcard */
	if (*s2 == '*')
	{
		/* If s1 ended but s2 has more after '*', no match */
		if (*s1 == '\0' && *(s2 + 1) != '\0')
			return (0);

		/* Try: skip '*' OR skip character in s1 */
		if (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)))
			return (1);
		return (0);
	}

	/* Current characters match */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* No match */
	return (0);
}


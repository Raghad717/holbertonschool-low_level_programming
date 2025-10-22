#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the integer converted from the string
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int started = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			started = 1;
			/* Check for overflow before multiplying */
			if (result > (2147483647 - (*s - '0')) / 10)
			{
				if (sign == 1)
					return (2147483647);
				else
					return (-2147483648);
			}
			result = result * 10 + (*s - '0');
		}
		else if (started)
		{
			/* Stop if we've started processing digits and encounter non-digit */
			break;
		}
		s++;
	}

	return (result * sign);
}

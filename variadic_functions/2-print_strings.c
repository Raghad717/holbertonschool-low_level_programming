#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings followed by a new line
 * @separator: string to print between strings
 * @n: number of strings passed to the function
 * @...: variable number of string parameters
 *
 * Description: Prints all strings with separator between them.
 * If separator is NULL, it's not printed.
 * If a string is NULL, prints "(nil)" instead.
 * No separator after the last string.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}

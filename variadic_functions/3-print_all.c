#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed to the function
 * @...: variable number of arguments
 *
 * Description: Prints arguments based on format specifiers.
 * c: char, i: integer, f: float, s: char* (prints (nil) if NULL)
 * Other characters in format are ignored.
 * Arguments are printed separated by commas.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *str;
	char sep[] = ", ";

	va_start(args, format);

	while (format && format[i])
	{
		if (j)
			printf("%s", sep);
		j = 0;
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				j = 1;
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				j = 1;
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				j = 1;
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s", str);
				j = 1;
				break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

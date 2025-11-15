#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments (c: char, i: int, f: float, s: char*)
 * @...: variable arguments
 *
 * Description: Prints arguments based on format specifiers.
 * 'c' - char, 'i' - int, 'f' - float, 's' - string (prints (nil) if NULL)
 * Other characters are ignored.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;
	char current;
	int separator = 0;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		current = format[i];
		if (separator && (current == 'c' || current == 'i' || current == 'f' || current == 's'))
			printf(", ");

		if (current == 'c')
		{
			printf("%c", va_arg(args, int));
			separator = 1;
		}
		if (current == 'i')
		{
			printf("%d", va_arg(args, int));
			separator = 1;
		}
		if (current == 'f')
		{
			printf("%f", va_arg(args, double));
			separator = 1;
		}
		if (current == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
			separator = 1;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

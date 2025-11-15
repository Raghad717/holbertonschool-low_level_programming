#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

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

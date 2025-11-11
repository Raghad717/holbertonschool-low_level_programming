#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: function pointer that determines how to print the name
 *
 * Description: This function takes a name and a function pointer,
 * then calls the function pointed to by @f, passing @name as argument.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

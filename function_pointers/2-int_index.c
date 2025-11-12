#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: array of integers to search
 * @size: number of elements in the array
 * @cmp: function pointer to compare values
 *
 * Return: index of first matching element, or -1 if no match or error
 *
 * Description: Iterates through the array and applies the comparison
 * function to each element. Returns the index of the first element
 * for which the comparison function returns non-zero.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}
	return (-1);
}

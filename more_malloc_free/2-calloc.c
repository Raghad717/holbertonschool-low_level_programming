#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;
	char *char_ptr;
	unsigned int i;

	/* Check for zero parameters */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Calculate total memory needed */
	total_size = nmemb * size;

	/* Allocate memory */
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	/* Set memory to zero */
	char_ptr = (char *)ptr;
	for (i = 0; i < total_size; i++)
		char_ptr[i] = 0;

	return (ptr);
}

#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the reallocated memory block
 *         NULL if new_size is zero and ptr is not NULL, or if malloc fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size;

	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));

	/* If new_size is 0 and ptr is not NULL, equivalent to free(ptr) */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If new_size == old_size, do nothing and return ptr */
	if (new_size == old_size)
		return (ptr);

	/* Allocate new memory block */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Copy contents from old block to new block */
	/* Copy up to the minimum of old_size and new_size */
	min_size = (old_size < new_size) ? old_size : new_size;
	memcpy(new_ptr, ptr, min_size);

	/* Free the old memory block */
	free(ptr);

	return (new_ptr);
}

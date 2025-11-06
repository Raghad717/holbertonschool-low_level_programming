#include "main.h"
#include <stdlib.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i, min_size;
	char *char_old, *char_new;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Manual copy without memcpy */
	char_old = (char *)ptr;
	char_new = (char *)new_ptr;
	min_size = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < min_size; i++)
		char_new[i] = char_old[i];

	free(ptr);
	return (new_ptr);
}

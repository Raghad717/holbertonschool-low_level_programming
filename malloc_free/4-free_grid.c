#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: pointer to the 2D array to free
 * @height: height of the grid (number of rows)
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	/* Check if grid is NULL */
	if (grid == NULL)
		return;

	/* Free each row (individual arrays) */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* Free the array of pointers */
	free(grid);
}

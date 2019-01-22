#include <stdio.h>

/*
** Starting in the top left corner of a 2×2 grid, and only being able to move to
** the right and down, there are exactly 6 routes to the bottom right corner.
** How many such routes are there through a 20×20 grid?
*/

#define MAX 20

int		main(void)
{
	unsigned long grid[MAX + 1][MAX + 1];
	for (int i = 1; i <= MAX; i++)
	{
		grid[i][0] = 1;
		grid[0][i] = 1;
	}
	for (int n = 1; n <= MAX; n++)
	{
		for (int i = 1; i <= MAX; i++)
			grid[n][i] = grid[n - 1][i] + grid[n][i - 1];
	}
	printf("%lu\n", grid[MAX][MAX]);
	return 0;
}

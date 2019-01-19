#include <stdio.h>

#define SIDE 20

int		max_product(int arr[SIDE][SIDE], int n, int i)
{
	int max = 0;
	if (i + 3 < SIDE)
		max = arr[n][i] * arr[n][i + 1] * arr[n][i + 2] * arr[n][i + 3];
	int tmp = 0;
	if (n + 3 < SIDE)
		tmp = arr[n][i] * arr[n + 1][i] * arr[n + 2][i] * arr[n + 3][i];
	if (tmp > max)
		max = tmp;
	if (i > 2 && n + 3 < SIDE)
		tmp = arr[n][i] * arr[n + 1][i - 1] * arr[n + 2][i - 2] * arr[n + 3][i - 3];
	if (tmp > max)
		max = tmp;
	if (i + 3 < SIDE && n + 3 < SIDE)
		tmp = arr[n][i] * arr[n + 1][i + 1] * arr[n + 2][i + 2] * arr[n + 3][i + 3];
	return max > tmp ? max : tmp;
}

int		main(void)
{
	int numbers[SIDE][SIDE];
	FILE *file = fopen("largest_product_in_a_grid_numbers", "r");
	for (int n = 0; n < SIDE * SIDE; n++)
	{
		for (int i = 0; i < SIDE; i++)
			fscanf(file, "%d", &numbers[n][i]);
	}
	fclose(file);

	int max = 0;
	for (int n = 0; n < SIDE; n++)
	{
		for (int tmp, i = 0; i < SIDE; i++)
		{
			if ((tmp = max_product(numbers, n, i)) > max)
				max = tmp;
		}		
	}
	printf("%d\n", max);
}

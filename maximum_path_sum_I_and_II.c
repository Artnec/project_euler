#include <stdio.h>

/*
** By starting at the top of the triangle below and moving to
** adjacent numbers on the row below, the maximum total from top to bottom is 23.

**    3
**   7 4
**  2 4 6
** 8 5 9 3

** That is, 3 + 7 + 4 + 9 = 23.
** Find the maximum total from top to bottom of bigger triangle.
*/


/*
** triangle for problem 18 is in maximum_path_sum_I_triangle file, set MAX_HIGHT to 15.
** triangle for problem 67 is in maximum_path_sum_II_triangle file, set MAX_HIGHT to 100.
*/

#define MAX_HIGHT	15
#define MAX_SIZE	((MAX_HIGHT + 1) * MAX_HIGHT) / 2

int		max(int a, int b)
{
	return a > b ? a : b;
}

int		main(void)
{
	int arr[MAX_SIZE + 1];
	int n = 0;
	while (n <= MAX_SIZE && scanf("%d", &arr[n]) != -1)
		n++;

	if (n != MAX_SIZE)
	{
		printf("error: triangle with height %d must have exactly %d numbers\n", MAX_HIGHT, MAX_SIZE);
		return 1;
	}

	for (int j = MAX_SIZE - 1, i = MAX_HIGHT; i > 0; i--, j--)
	{
		for (int t = i; t > 1; t--, j--)
			arr[j - i] += max(arr[j], arr[j - 1]);
	}
	printf("%d\n", arr[0]);
}

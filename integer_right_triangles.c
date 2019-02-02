#include <stdio.h>
#include <math.h>

/*
** problem can be found at https://projecteuler.net/problem=39
*/

#define MAXIMUM_PERIMETER 1000

int		maximum_triangles(int p)
{
	int count = 0;
	for (int a = 1; a <= p / 4; a++)
	{
		for (int b = a + 1; b <= (p - a) / 2; b++)
		{
			int c = p - a - b;
			if (pow(a, 2) + pow(b, 2) == pow(c, 2))
				count++;
		}
	}
	return count;
}

int		main(void)
{
	int max = 0, max_p = -1;
	for (int p = 3; p <= MAXIMUM_PERIMETER; p++)
	{
		int tmp = maximum_triangles(p);
		if (tmp > max)
		{
			max = tmp;
			max_p = p;
		}
	}
	printf("%d\n", max_p);
}

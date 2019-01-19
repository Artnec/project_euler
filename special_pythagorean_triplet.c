#include <stdio.h>

/*
** A Pythagorean triplet is a set of three natural numbers,
** a < b < c, for which, a2 + b2 = c2. For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
** There exists exactly one Pythagorean triplet for which a + b + c = 1000.
** Find the product abc.
*/

int		main(void)
{
	for (int a = 1; a < 333; a++)
	{
		for (int b = a + 1; b < 500; b++)
		{
			int c = 1000 - a - b;
			if (c <= b)
				break ;
			if (a * a + b * b == c * c)
			{
				printf("%d\n", a * b * c);
				return 0 ;
			}
		}
	}
	return 0;
}

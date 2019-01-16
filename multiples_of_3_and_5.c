#include <stdio.h>

/*
** If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
** The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
*/

#define MAX 999L

long	range_sum(int num)
{
	return (MAX / num + 1) * (MAX / num) * num / 2;
}

int		main(void)
{
	printf("%ld\n", range_sum(5) + range_sum(3) - range_sum(3 * 5));
	return 0;
}

#include <stdio.h>

/*
** 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
** What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

long	greatest_common_divisor(long a, long b)
{
	if (b == 0)
		return a;
	return greatest_common_divisor(b, a % b);
}

long	least_common_multiple(int bigest)
{
	long ret = 1;
	for (int i = bigest / 2 + 1; i <= bigest; i++)
		ret = (ret * i) / greatest_common_divisor(ret, i);
	return ret;
}

int		main(void)
{
	printf("%ld\n", least_common_multiple(20));
	return 0;
}

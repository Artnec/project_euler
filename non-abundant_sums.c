#include <stdio.h>

/*
** A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
** For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
** A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
** As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
** By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
** However, this upper limit cannot be reduced any further by analysis even though it is known
** that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
** Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#define LIMIT 28123

int		main(void)
{
	int divisors_sum[LIMIT] = {0};
	for (int i = 2; i < LIMIT; i++)
	{
		divisors_sum[i]++;
		for (int j = i + i; j < LIMIT; j += i)
			divisors_sum[j] += i;
	}

	int abundant[LIMIT] = {0}, n = 0;
	for (int i = 0; i < LIMIT; i++)
	{
		if (divisors_sum[i] > i)
			abundant[n++] = i;
	}

	char posible_sums[LIMIT] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (abundant[i] + abundant[j] < LIMIT)
				posible_sums[abundant[i] + abundant[j]] = 1;
		}
	}

	int sum = 0;
	for (int i = 1; i < LIMIT; i++)
	{
		if (posible_sums[i] == 0)
			sum += i;
	}
	printf("%d\n", sum);
}

#include <stdio.h>

/*
** problem can be found at https://projecteuler.net/problem=34
*/

int		factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int		sum_factorials_of_digits(int n, int *factorials)
{
	int sum = 0;
	while (n > 0)
	{
		sum += factorials[n % 10];
		n /= 10;
	}
	return sum;
}

int		main(void)
{
	int factorials[10];
	for (int i = 0; i < 10; i++)
		factorials[i] = factorial(i);

	int sum = 0;
	for (int i = 3; i < 10000000; i++)
	{
		if (i == sum_factorials_of_digits(i, factorials))
			sum += i;
	}
	printf("%d\n", sum);
}

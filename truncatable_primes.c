#include <stdio.h>
#include <math.h>

/*
** problem can be found at https://projecteuler.net/problem=37
*/

#define MAX 1000000

int		num_len(int n)
{
	int len = 1;
	while (n /= 10)
		len++;
	return len;
}

int		is_truncatable_prime(int n, char *primes)
{
	for (int p = n / 10; p > 0; p /= 10)
	{
		if (primes[p] == 1)
			return 0;
	}
	for (int m = pow(10, num_len(n) - 1); m > 1; m /= 10)
	{
		if (primes[n % m] == 1)
			return 0;
	}
	return 1;
}

int		main(void)
{
	char primes[MAX] = {1, 1, 0};
	for (int i = 2; i < MAX; i++)
	{
		for (int n = i + i; n < MAX; n += i)
			primes[n] = 1;
	}

	int sum = 0, count = 0;
	for (int i = 11; i < MAX; i++)
	{
		if (primes[i] == 0 && is_truncatable_prime(i, primes))
		{
			sum += i;
			if (++count == 11)
				break ;
		}
	}
	printf("%d\n", sum);
}

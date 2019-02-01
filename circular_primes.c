#include <stdio.h>
#include <math.h>

/*
** problem can be found at https://projecteuler.net/problem=35
*/

#define MAX 1000000

int		num_len(int n)
{
	int len = 1;
	while (n /= 10)
		len++;
	return len;
}

int		rotate(int n, int len)
{
	int s = n % 10 * pow(10, len - 1);
	return n / 10 + s;
}

int		is_circular_prime(int n, char *primes)
{
	int len = num_len(n);
	for (int i = len; i > 1; i--)
	{
		n = rotate(n, len);
		if (primes[n] == 1)
			return 0;
	}
	return 1;
}

int		main(void)
{
	char primes[MAX] = {0};
	for (int i = 2; i < MAX; i++)
	{
		for (int n = i + i; n < MAX; n += i)
			primes[n] = 1;
	}

	int count = 0;
	for (int i = 2; i < MAX; i++)
	{
		if (primes[i] == 0 && is_circular_prime(i, primes))
			count++;
	}
	printf("%d\n", count);
}

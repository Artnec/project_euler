#include <stdio.h>
#include <stdlib.h>

/*
** The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
** Find the sum of all the primes below two million.
*/

#define MAX 2000000

// using Sieve of Eratosthenes algorithm

int		main(void)
{
	char *arr = calloc(MAX, 1);
	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] == 0)
		{
			for (int n = i + i; n < MAX; n += i)
				arr[n] = 1;
		}
	}

	long sum = 0;
	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] == 0)
			sum += i;
	}
	printf("%ld\n", sum);
}

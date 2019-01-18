#include <stdio.h>

/*
** By listing the first six prime numbers: 2, 3, 5, 7, 11, 13, we can see that the 6th prime is 13.
** What is the 10 001st prime number?
*/

#define MAX	10001

int		is_prime(int num)
{
	if (num <= 1)
		return 0;
	if (num <= 3)
		return 1;
	if (num % 2 == 0 || num % 3 == 0)
		return 0;

	for (int i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return 0;
	}
	return 1;
}

int		main(void)
{
	long i = 3;
	for (int num = 1; num < MAX; i += 2)
	{
		if (is_prime(i))
			num++;
	}
	printf("%ld\n", i - 2);
	return 0;
}

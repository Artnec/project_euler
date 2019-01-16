#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
** The prime factors of 13195 are 5, 7, 13 and 29.
** What is the largest prime factor of the number 600851475143 ?
*/

long		largest_prime_factor(long num)
{
	long i = 2;
	while (i < num)
	{
		if (num % i == 0)
		{
			printf("%ld\n", i); // print all prime factors
			num /= i;
		}
		else
			i++;
	}
	return i;
}

int		main(void)
{
	printf("%ld\n", largest_prime_factor(600851475143L));
	return 0;
}

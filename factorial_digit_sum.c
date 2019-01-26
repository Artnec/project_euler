#include <stdio.h>
#include <stdlib.h>

/*
** n! means n × (n − 1) × ... × 3 × 2 × 1
** For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
** and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
** Find the sum of the digits in the number 100!
*/

#define FACTORIAL	100
#define BUF_SIZE 	1024  // up to 458, increase BUF_SIZE when calculating larger factorial

int		count_digits(char *f, int e)
{
	int count = 0;
	for (int i = 0; i < e; i++)
		count += f[i];
	return count;
}

void	print_large_factorial(char *f, int e)
{
	while (--e >= 0)
		printf("%d", f[e]);
	printf("\n");
}

int		large_factorial(char *f, int max)
{
	f[0] = 1;
	int end = 1, carry = 0;
	for (int i = 1; i <= max; i++)
	{
		for (int j = 0; j < end; j++)
		{
			int x = f[j] * i + carry;
			f[j] = x % 10;
			carry = x / 10;
		}
		while (carry > 0)
		{
			f[end] = carry % 10;
			carry /= 10;
			if (++end == BUF_SIZE)
			{
				printf("error: factorial too large, increase BUF_SIZE\n");
				exit(1);
			}
		}
	}
	print_large_factorial(f, end);
	return count_digits(f, end);
}

int		main(void)
{
	char factorial[BUF_SIZE];
	printf("%d\n", large_factorial(factorial, FACTORIAL));
}

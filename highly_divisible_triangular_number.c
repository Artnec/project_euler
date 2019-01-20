#include <stdio.h>

#define MAX 500

int		count_divisors(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
			sum++;
	}
	return sum;
}

int		cd(int num)
{

}

100  1 2 4 5 10 20 25 50 100

int		main(void)
{
	for (int i = 5984, n = 17907120;; n += i + 1, i++)
	{
		if (count_divisors(n) > MAX)
		{
			printf("%d\n", n);
			printf("i %d\n", i);
			break ;
		}
	}
	return 0;
}

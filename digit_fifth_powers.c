#include <stdio.h>
#include <math.h>

#define POW 5

int		sum_pows(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += pow(num % 10, POW);
		num /= 10;
	}
	return sum;
}

int		find_limit(void)
{
	for (int max = 9; max < 1000000000; max = max * 10 + 9)
	{
		if (max > sum_pows(max))
		{
			while (max / 2 > sum_pows(max / 2))
				max /= 2;
			return max;
		}
	}
	return -1;
}

int		main(void)
{
	int sum = 0;
	for (int limit = find_limit(), i = 2; i < limit; i++)
	{
		if (sum_pows(i) == i)
			sum += i;
	}
	printf("%d\n", sum);
}

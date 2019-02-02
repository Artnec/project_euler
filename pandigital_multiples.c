#include <stdio.h>
#include <math.h>

/*
** problem can be found at https://projecteuler.net/problem=38
*/

int		num_len(int n)
{
	int len = 1;
	while (n /= 10)
		len++;
	return len;
}

int		contains_every_digit(int n)
{
	char d[10] = {0};
	for (; n > 0; n /= 10)
		d[n % 10]++;
	for (int i = 1; i < 10; i++)
	{
		if (d[i] != 1)
			return 0;
	}
	return 1;
}

int		make_pandigital(int number, int max_multiplier)
{
	int len = 1000000000 / pow(10, num_len(number));
	int num = number * len;
	for (int i = 2; i <= max_multiplier; i++)
	{
		len /= pow(10, num_len(number * i));
		num += number * i * len;
		if (num >= 1000000000 || num < 100000000)
			return -1;
	}
	if (!contains_every_digit(num))
		return -1;
	return num;
}

int		main(void)
{
	int max = 0;
	for (int i = 9; i < 9876; i++)
	{
		int max_n = 10 / num_len(i);
		for (int n = 2; n <= max_n; n++)
		{
			int tmp = make_pandigital(i, n);
			if (tmp > max)
				max = tmp;
		}
	}
	printf("%d\n", max);
}

#include <stdio.h>

int		is_pandigital(int a, int b)
{
	char numbers[10] = {0};
	for (int n = a * b; n > 0; n /= 10)
		numbers[n % 10]++;
	for (; a > 0; a /= 10)
		numbers[a % 10]++;
	for (; b > 0; b /= 10)
		numbers[b % 10]++;
	if (numbers[0] != 0)
		return 0;
	for (int i = 1; i < 10; i++)
	{
		if (numbers[i] != 1)
			return 0;
	}
	return 1;
}

int		main(void)
{
	char nums[10000] = {0};
	int sum = 0;
	for (int n = 2; n < 50; n++)
	{
		for (int i = 100; i < 10000 / n; i++)
		{
			if (is_pandigital(n, i))
			{
				if (nums[n * i] == 0)
					sum += n * i;
				nums[n * i] = 1;
			}
		}
	}
	printf("%d\n", sum);
}

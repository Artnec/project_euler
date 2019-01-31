#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX			2048
#define BUF_SIZE	MAX

void	divide_one(char *num, int div)
{
	int rem = 1;
	for (int i = 0; i < MAX && rem % div != 0; i++)
	{
		num[i] = (rem * 10) / div + '0';
		rem = (rem * 10) % div;
	}
}

int		cyclic_numbers_count(char *num)
{
	if (num[MAX - 1] == '\0')
		return 0;
	for (int n = MAX - 2; n > 0; n--)
	{
		for (int j = n, i = MAX - 1; j >= 0 && num[i] == num[j]; i--, j--)
		{
			if (i == n && n + 10 < MAX)
				return MAX - n - 1;
		}
	}
	printf("error: need bigger BUF_SIZE\n");
	exit(1);
	return -1;
}

int		main(void)
{
	char num[MAX + 1];
	int max = 0, max_idx = 0, tmp;
	for (int i = 2; i < 1000; i++)
	{
		memset(num, 0, sizeof(num));
		divide_one(num, i);
		if ((tmp = cyclic_numbers_count(num)) > max)
		{
			max = tmp;
			max_idx = i;
		}
	}
	printf("%d\n", max_idx);
}

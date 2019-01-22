#include <stdio.h>

/*
** 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
** What is the sum of the digits of the number 2^1000?
*/

#define POW	1000
#define MAX	(POW / 2)

void	big_pow2(char *num, int len)
{
	for (int n = 1; n < POW; n++)
	{
		for (int next = 0, i = len - 1; i >= 0; i--)
		{
			if (num[i] <= 4)
			{
				num[i] = num[i] * 2 + next;
				next = 0;
			}
			else
			{
				num[i] = num[i] * 2 - 10 + next;
				next = 1;
			}
		}
	}
}

int		sum_digits(char *num, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += num[i];
	return sum;
}

int		main(void)
{
	char num[MAX] = {0};
	num[MAX - 1] = 2;
	big_pow2(num, MAX);

	printf("%d\n", sum_digits(num, MAX));
	return 0;
}

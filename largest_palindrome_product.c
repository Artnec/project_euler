#include <stdio.h>

int		reverse_int(int num)
{
	int rev = 0;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	return rev;
}

int		main(void)
{
	int max = 0;
	for (int i, a = 999; a > 99; a--)
	{
		for (int b = a; b > 99; b--)
		{
			i = a * b;
			if (i == reverse_int(i) && i > max)
				max = i;
		}
		if (max >= a * a)
			break ;
	}
	printf("%d\n", max);
	return 0;
}

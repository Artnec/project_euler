#include <stdio.h>

#define MAX_SIDE 1001

int		main(void)
{
	long tmp = 1, sum = 1;
	for (int n = 1; n < MAX_SIDE / 2 + 1; n++)
	{
		for (int j = 0; j < 4; j++)
		{
			tmp += n * 2;
			sum += tmp;
		}
	}
	printf("%ld\n", sum);
}

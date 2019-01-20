#include <stdio.h>
#include <string.h>

void	add(char *a, int al, char *b, int bl)
{
	while (--bl >= 0)
	{
		al--;
		if (a[al] + b[bl] - '0' <= '9')
			a[al] += b[bl] - '0';
		else
		{
			a[al] += b[bl] - '0' - 10;
			a[al - 1]++;
		}
	}
	while (al > 0 && a[--al] > '9')
	{
		a[al] -= 10;
		a[al - 1]++;
	}
}

int		main(void)
{
	char sum[64];
	memset(sum, '0', sizeof(sum));
	FILE *fp = fopen("large_sum_numbers", "r");
	fscanf(fp, "%50s", sum + 13);
	char buf[51];
	for (int i = 1; i < 100; i++)
	{
		fscanf(fp, "%50s", buf);
		add(sum, sizeof(sum) - 1, buf, sizeof(buf) - 1);
	}
	fclose(fp);
	int i = 0;
	while (sum[i] == '0' && i < sizeof(sum))
		i++;
	printf("%s\n", sum + i);
	return 0;
}

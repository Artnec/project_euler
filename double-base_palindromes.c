#include <stdio.h>
#include <string.h>
/*
** problem can be found at https://projecteuler.net/problem=36
*/

#define MAX 1000000

int		num_len(int n, int base)
{
	int len = 1;
	while (n /= base)
		len++;
	return len;
}

char	*to_str(int n, int base, char *str)
{
	int len = num_len(n, base);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = n % base + '0';
		n /= base;
	}
	return str;
}

int		is_palindrom(char *str)
{
	for (int s = 0, e = strlen(str) - 1; s < e; s++, e--)
	{
		if (str[s] != str[e])
			return 0;
	}
	return 1;
}

int		main(void)
{
	char str[33];
	int sum = 0;
	for (int n = 1; n < MAX; n++)
	{
		if (n % 2 == 1 && is_palindrom(to_str(n, 10, str)) && is_palindrom(to_str(n, 2, str)))
			sum += n;
	}
	printf("%d\n", sum);
}

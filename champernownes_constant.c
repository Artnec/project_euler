#include <stdio.h>

/*
** problem can be found at https://projecteuler.net/problem=40
*/

#define MAX 1000000

long	multiply(char *s)
{
	long n = 1;
	for (int i = 1; i <= MAX; i *= 10)
		n = n * (s[i] - '0');
	return n;
}

int		main(void)
{
	char s[MAX + 10];
	for (int n = 1, i = 1; i <= MAX; n++)
		i += sprintf(s + i, "%d", n);
	printf("%ld\n", multiply(s));
}

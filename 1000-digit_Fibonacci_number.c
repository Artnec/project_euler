#include <stdio.h>
#include <string.h>

#define MAX_DIGITS	1000

void	reverse(char *str)
{
	for (int s = 0, e = strlen(str) - 1; s < e; s++, e--)
	{
		char tmp = str[s];
		str[s] = str[e];
		str[e] = tmp;
	}
}

int		add(char *to, char *from)
{
	int i;
	for (i = 0; from[i] != '\0'; i++)
	{
		if (to[i] + from[i] - '0' <= '9')
			to[i] += from[i] - '0';
		else
		{
			to[i] += from[i] - '0' - 10;
			to[i + 1] = (to[i + 1] == '\0' ? '1' : to[i + 1] + 1);
		}
	}
	if (to[i] != '\0')
		i++;
	return i == MAX_DIGITS;
}

int		main(void)
{
	char prev[MAX_DIGITS] = {0};
	prev[0] = '1';
	char tmp[MAX_DIGITS] = {0};
	char next[MAX_DIGITS + 1] = {0};
	next[0] = '1';

	int i = 2;
	for (;;)
	{
		i++;
		strcpy(tmp, next);
		if (add(next, prev) == 1)
			break ;
		strcpy(prev, tmp);
	}
	// reverse(next);
	// printf("%s\n", next); // print factorial
	printf("%d\n", i);
}

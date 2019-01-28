#include <stdio.h>
#include <string.h>

/*
** Using names.txt, a 46K text file containing over five-thousand first names,
** begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
** multiply this value by its alphabetical position in the list to obtain a name score.
** For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
** is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
** What is the total of all the name scores in the file?
*/

int		seperate_names(char *buf, char names[6000][32])
{
	int n = 0;
	for (int i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '"')
		{
			int j = 0;
			for (i += 1; buf[i] != '\0' && buf[i] != '"'; i++, j++)
				names[n][j] = buf[i];
			names[n++][j] = '\0';
		}
	}
	return n;
}

void	sort_names(char *names_p[], int len)
{
	for (int n = 0; n < len; n++)
	{
		for (int i = n + 1; i < len; i++)
		{
			if (strcmp(names_p[n], names_p[i]) > 0)
			{
				char *tmp = names_p[n];
				names_p[n] = names_p[i];
				names_p[i] = tmp;
			}
		}
	}
}

int		letters_sum(char *name)
{
	int sum = 0;
	for (int i = 0; name[i] != '\0'; i++)
		sum += name[i] - 'A' + 1;
	return sum;
}

int		main(void)
{
	char buf[50000];
	FILE *fp = fopen("names.txt", "r");
	fscanf(fp, "%s", buf);
	fclose(fp);

	char names[6000][32];
	int max = seperate_names(buf, names);
	char *names_p[max];
	for (int i = 0; i < max; i++)
		names_p[i] = names[i];

	sort_names(names_p, max);
	long sum = 0;
	for (int i = 0; i < max; i++)
		sum += letters_sum(names_p[i]) * (i + 1);
	printf("%ld\n", sum);
}

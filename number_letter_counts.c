#include <stdio.h>

char first_19[][20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char dec[][20] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int			main(void)
{
	int sum = 0;
	for (int n = 1; n < 1000; n++)
	{
		if (n >= 100)
			sum += printf("%s hundred ", first_19[n / 100]) - 2;
		if (n >= 100 && n % 100 != 0)
			sum += printf("and ") - 1;
		sum += printf("%s", dec[(n % 100) / 10]);
		if (n % 100 > 20)
		{
			if (n % 10 != 0)
				printf("-");
			sum += printf("%s", first_19[n % 10]);
		}
		else
			sum += printf("%s", first_19[n % 20]);
		printf("\n");
	}
	sum += printf("one thousand\n") - 2;
	printf("%d\n", sum);
}

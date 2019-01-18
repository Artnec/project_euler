#include <stdio.h>

/*
** The sum of the squares of the first ten natural numbers is, 12 + 22 + ... + 102 = 385
** The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)2 = 552 = 3025
** Hence the difference between the sum of the squares of the first ten natural numbers
** and the square of the sum is 3025 − 385 = 2640.
** Find the difference between the sum of the squares of the
** first one hundred natural numbers and the square of the sum.
*/

#define MAX 100L
#define SUM(n) ((n + 1) * (n))

int		main(void)
{
	printf("%ld\n", (SUM(MAX) * SUM(MAX) / 4) - (SUM(MAX) * (MAX * 2 + 1) / 6));	
	return 0;
}

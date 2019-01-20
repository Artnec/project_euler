#include <stdio.h>
#include <stdlib.h>

/*
** 
** The following iterative sequence is defined for the set of positive integers:
** 
** n → n/2 (n is even)
** n → 3n + 1 (n is odd)
** 
** Using the rule above and starting with 13, we generate the following sequence:
** 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
** It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
** Although it has not been proved yet (Collatz Problem),
** it is thought that all starting numbers finish at 1.
** Which starting number, under one million, produces the longest chain?
** NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#define MAX 1000000

int		callatz_sequence_len(int num, int *arr)
{
	int len = 1;
	for (unsigned long n = num; n != 1; len++)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		if (n < num)
			return arr[n] + len;
	}
	return len;
}

int		main(void)
{
	int *arr = calloc(MAX, sizeof(int));
	int max = 0, max_idx = 0;
	for (int i = 1; i < MAX; i++)
	{
		if ((arr[i] = callatz_sequence_len(i, arr)) > max)
		{
			max = arr[i];
			max_idx = i;
		}
	}
	free(arr);
	printf("%d %d\n", max, max_idx);
	return 0;
}

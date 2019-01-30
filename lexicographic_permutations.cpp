#include <algorithm>
#include <iostream>

int		main()
{
	char str[] = "0123456789";
	for (int len = strlen(str), i = 1; i < 1000000; i++)
		std::next_permutation(str, str + len);
	std::cout << str << std::endl;
}

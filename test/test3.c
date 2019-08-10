#include <stdio.h> 
void test_func(unsigned long long n)
{
	printf("the char is %llu\n", n);
}

int		main()
{
	unsigned char x;

	x = 'z'; 
	test_func(x);
	return (0);
}

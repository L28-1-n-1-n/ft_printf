#include <stdio.h>
int main()
{
	printf("digit is=%.0f\n", 0.0);
	printf("digit is=%.0f\n", 0);
	printf("digit is=%010.0f\n", -0.0);
	printf("digit is=%.0d\n", 0);
	printf("digit is=%# 15.10f\n", 0.01);
	printf("digit is %.0f\n", 15.7);
	return (0);
}

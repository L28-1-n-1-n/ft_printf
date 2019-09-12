#include <stdio.h>
#include <stdlib.h>

int main()
{
/*	printf("digit is=%.0f\n", 0.0);
	printf("digit is=%.0f\n", 0);
	printf("digit is=%010.0f\n", -0.0);
	printf("digit is=%.0d\n", 0);
	printf("digit is=%# 15.10f\n", 0.01);
	printf("digit is %#.0f\n", 15.7);
	printf("digit is=% 015.3f\n", 56.1234567);
	printf("float is %.000f\n", 0.0);*/

	printf("e is %#.30e\n", 0.00000000123456789);
	printf("e is %#.30f\n", 0.00000000123456789); 
	printf("e is %#.30g\n", 0.00000000123456789);
	printf("0.125 is %e\n", 0.125);
	printf("0.125 is %f\n", 0.125);
	printf("0.125 is %g\n", 0.125);
	printf("0.3 is % 030e\n", 0.312346);
	printf("9.1233 is %020e\n", 9.1233);
	printf("99.1233 is %020e\n", 99.1233);
	printf("123456.7890 %.12f\n", 123456.789012345);
	printf("123456.7890 %.12e\n", 123456.789012345);
	printf("123456.7890 %.12g\n", 123456.789012345);
	printf("flaot is %.12f\n", 0.000000123);
	printf("atoi(01) is %d\n", atoi("01"));
	return (0);
}

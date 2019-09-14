#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define isnan(x) ((x) != (x))
int main()
{
	long double n;
	n = 0;
	printf("n is %f\n", n);
	printf("0 is %f\n\n", 0);	
	printf("0 is %Lf\n\n", 0L);
	printf("n is %.20f\n", n);
	printf("0 is %.20f\n\n", 0);
	printf("0 is %Lf\n", 0.0L);
	printf("0 is %.20Lf\n", 0.0L);
//	printf("%.100Lf\n",45035996273);
	if (isnan(-INFINITY))
		printf("yes\n");
	else
		printf("no\n");
//	printf("0./0.=%+.500f\n", -11195354654646456545654654644645223372036854775808.02);
	printf("float=%-+020.30f\n", +INFINITY);
	printf("float=%+-020.30f\n", -(double)0);
//	printf("float=%.100f\n", 27262976);
//	printf("flaot=%.100f\n", 1/32);
	printf("nan is=%+-020.30f\n", 0./0.);
	printf("nan is=%+-020.30f\n", NAN);
//	printf("macro returns %d\n", FP_NAN(0./0.));
	printf("result is %llu\n", 6917529027641081856 >> 61);
	return (0);
}

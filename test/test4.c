#include <stdio.h>
#include <stdint.h>
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
	if (isnan(0x7FF0000000000001))
		printf("yes\n");
	else
		printf("no\n");
	printf("0./0.=%+.500f\n", 0x400921fb54442d18);
	return (0);
}

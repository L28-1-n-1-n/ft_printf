#include <stdio.h>
#include <stdint.h>
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
	printf("0 is %.20Lf\n". 0.0L);



	return (0);
}

#include <stdio.h>
#include <stdlib.h>

int		main()
{
/*	int i;

	i = 0;

	i |= 4;
	i |= 4;*/

//	printf("i is %d\n", i);
//	printf("%2$d %2$#x and then %1$d %1$#x, et puis %%\n", 16, 17);
//	printf("%#f\n", 23.0790234000000003);
//	printf("%d\n", atoi("00000034\n"));
//	printf("%2$0000 +-'   00 00#00020.5f %1$+d\n", 15, 23.081);
//	printf("%'f", 23067823490.0091);
//	printf("%14   d\n", 2);
/*	printf("1%%%12%% %12%%\n");
	printf("1%%12%% %12%%\n");
	printf("1%12%% %12%%\n");
	printf("%% %12\n");
	printf("%12%% %12%%\n");
	printf("%12% %%12%%\n");
	printf("%%%12%%");*/
/*
	printf("HEX %20x\n", 652);
	printf("HEX %20.2x\n", 652);
	printf("HEX %-20.2x\n", 652);
	printf("HEX %0#20X\n", 652);
	printf("HEX %#20x\n", 652);
	printf("HEX %'#20x\n", 652);
	printf("HEX %20x\n", -64);
	printf("HEX %20x\n", 652);*/

//	printf("HEX %hhx\n", (char)-12);
	printf("size of char is %lu\n", sizeof(char));
	printf("size of unsigned int is %lx\n", sizeof(unsigned int));
	printf("size of unsigned char is %lx\n", sizeof(unsigned char));
	printf("size of unsigned short is %lx\n", sizeof(unsigned short));
	printf("size of unsigned long is %lx\n", sizeof(unsigned long));
	printf("size of unsigned long long  is %lx\n", sizeof(unsigned long long));
	printf("size of long is %lx\n", sizeof(long));
	printf("size of long long is %lx\n", sizeof(long long));
	printf("size of size_t  is %lx\n", sizeof(size_t));
	printf("size of long double is %lu\n", sizeof(long double));
	printf("size of intmax_t is %lu\n", sizeof(intmax_t));
//	printf("HEX 64 is %llx\n", 64234234234234234);
//	printf("HEX -64 is %llx\n", -64234234234234234);
//	printf("dec - 64 is  %d\n", 2147483647);	
	printf("hex 4,294,967,296 is %lx\n", 4294967296);
	printf("hex 4,294,967,295 is %lx\n", 4294967295);
	printf("hex 4,294,967,297 is %lx\n", 4294967297);
	printf("hex 9223372036854775808 is %#+40llo\n", -9223372036854775808);
	printf("hex 1 is %-0#x\n", 1);
	printf(" 8 & 16 is %d\n", 8 & 16);
	printf("now octal 8 = %-#12o, -16 = %#o, 32 = %o, -64 = %#20o\n",8, -16, 32, -64); 
	printf("2^62 is %lo\n", 4611686018427387904);
//	printf("2 ^ 127 is %llo\n",  36893488147419103232);
	printf("neg 2^31 is %lx\n", -2147483648);
	intmax_t k;

	k = 15;
	printf("1111 << 60 is %lld\n", k<< 60);


	char s[200];
	

	printf("pointer %30p\n", s);

	return (0);
}

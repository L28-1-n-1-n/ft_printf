#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int i;

	i = 0;

	i |= 4;
	i |= 4;

	printf("i is %d\n", i);
//	printf("%2$d %2$#x and then %1$d %1$#x, et puis %%\n", 16, 17);
//	printf("%#f\n", 23.0790234000000003);
	printf("%d\n", atoi("00000034\n"));
	printf("%2$0000 +-'   00 00#00020.5f %1$+d\n", 15, 23.081);
	printf("%'f", 23067823490.0091);
//	printf("%14   d\n", 2);
/*	printf("1%%%12%% %12%%\n");
	printf("1%%12%% %12%%\n");
	printf("1%12%% %12%%\n");
	printf("%% %12\n");
	printf("%12%% %12%%\n");
	printf("%12% %%12%%\n");
	printf("%%%12%%");*/
	return (0);
}

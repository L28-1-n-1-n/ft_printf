#include <stdio.h>

int		main(int ac, char **av)
{
		int	ret[2];
		char	*str = "astek";
		char	stre[] = {'a', 's', 10, 'e', 'k', 0};

		(void)ac;
		(void)av;
		printf("##### Tests simple : 1 point par test reussi #####\n");
		printf(   "0) Modulo [%%] : {%%}\n");
	//	my_printf("=> Modulo [%%] : {%%}\n");
		printf(   "1) Nombre signe [d] : {%d}\n", 42);
	//my_printf("=> Nombre signe [d] : {%d}\n", 42);
		printf(   "2) Nombre signe [i] : {%i}\n", 42);
	//	my_printf("=> Nombre signe [i] : {%i}\n", 42);
		printf(   "3) Nombre octal [o] : {%o}\n", 012345);
	//	my_printf("=> Nombre octal [o] : {%o}\n", 012345);
		printf(   "4) Nombre non signe [u] : {%u}\n", 42);
	//	my_printf("=> Nombre non signe [u] : {%u}\n", 42);
		printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
	//	my_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
		printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
	//	my_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
		printf(   "7) Nombre binaire [b] : {101111101111110000001}\n");
	//	my_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
		return (0);
}

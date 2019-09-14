#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str1;
	char *str2;

	str1 = (char *)malloc(sizeof(char) * 5);
	str2 = (char *)malloc(sizeof(char) * 5);
	
	strcpy(str1, "hello\n");
	strcpy(str2, str1);
	free(str1);
	strcpy(str2, "world\n");
	
	*str1 = *str2;
	printf("str1=%s\n", str1);
	printf("str2=%s\n", str2);
	return (0);
}

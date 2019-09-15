#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch = '\t';
	
	if (isprint(ch))
		fputc(ch, stdout);  /* Printable character, print it directly */
	else
	{
		switch (ch)
		{
			case '\n':
				printf("\\n");
				break;

				

			default:
					/* A character we don't know, print it's hexadecimal value */
					printf("\\x%02x", ch);
					break;
		}
	}
	return (0);
}

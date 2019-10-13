#include "printf.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
void find_date(char *final, time_t seconds)
{
	int d;
	int mon;
	int y;
	int rem;
	y = (int)(seconds / 31556926) + 1970;
//	mon = (int)((seconds - ((((seconds - (seconds / 31556926) * 31556926) / 2629743) * 2629743))) / 86400);
//	rem = (int)(seconds - ((seconds / 31556926) * 31556926));
//		printf("rem is %d\n", rem);
//	mon = ((seconds / 2629743) - (seconds / 2629743) / 12);
mon  = (int)(seconds / 86400) - 365 *(seconds / 31556926);
//	rem = rem % 2629743;
		//mon = rem - ((rem / 2629743) * 2629743);
//	mon = (int)((seconds - (seconds / 31556926) * 31556926) / 2629743);
//	mon = (int)(((seconds % 31556926) % 2629743) / 86400);
	printf("Year is %d\n", y);
	//printf("rem is %d\n", rem);
	printf("Month is %d\n", mon);
}
*/

char *find_month(char *iso, char *month)
{
	(void)iso;
	//const char *months[12];
	 //{"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "August", "September", "October", "November", "December"};
	if (!(ft_strcmp(month, "Jan")))
		return ("01");
	if (!(ft_strcmp(month, "Feb")))
		return ("02");
	if (!(ft_strcmp(month, "Mar")))
		return ("03");
	if (!(ft_strcmp(month, "Apr")))
		return ("04");
	if (!(ft_strcmp(month, "May")))
		return ("05");
	if (!(ft_strcmp(month, "Jun")))
		return ("06");
	if (!(ft_strcmp(month, "Jul")))
		return ("07");
	if (!(ft_strcmp(month, "Aug")))
		return ("08");
	if (!(ft_strcmp(month, "Sep")))
		return ("09");
	if (!(ft_strcmp(month, "Oct")))
		return ("10");
	if (!(ft_strcmp(month, "Nov")))
		return ("11");
	if (!(ft_strcmp(month, "Dec")))
		return ("12");
	return (0);
}
void find_timezone(char *iso, time_t seconds)
{
		char buf[6];
		struct tm *ptm;

		ft_bzero(buf, 6);
		ptm = localtime(&seconds);
		strftime(buf, 6, "%z", ptm);
		//struct tm *ptm = localtime(&seconds);
		strftime(buf, 6, "%z", ptm);
		ft_strncat(iso, buf, 5);
}
int treat_time(char *final, t_block *blksk)
{
//	int h;
//	int m;
//	int s;
	time_t seconds;
	char str[25];
	char **result;
	char iso[26];
	int i;
	(void)blksk;
	i = 0;
	ft_bzero(str, 25);
	ft_bzero(iso, 26);
	time(&seconds);
	ft_strcpy(str, ctime(&seconds));
	result = ft_strsplit(str, ' ');
	ft_strncpy(iso, result[4], 4);
	iso[4] = '-';
	ft_strncat(iso, find_month(iso, result[1]), 3);//
	iso[7] = '-';
	ft_strcat(iso, result[2]);
	ft_strcat_char(iso, 'T');
	ft_strcat(iso, result[3]);
	find_timezone(iso, seconds);
	ft_strcat(final, iso);
	return (0);
}
/*
1994-11-05T08:15:30-05:00
Mon Sep 16 06:36:29 2019
0   1   2   3       4
length is 25
int main()
{
	char *final;
	final = 0;
	treat_time(final);
	return (0);
}
*/

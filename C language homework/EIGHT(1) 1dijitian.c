#include <stdio.h>
typedef struct date
{
	int year;
	int month;
	int day;
}date;
void days(date)
{
	int y,m,d;
	scanf("%d %d %d",&date.year,date.month,date.day);
	int md[12]={31,0,31,30,31,30,31,31,30,31,30,31};
	int s=0,i;
	if(y%4==0&&y%100!=0||y%400==0)
	  {md[1]=29;}
	else
	{md[1]=28;}
	for(i=0;i<m-1;i++)
	    {
	    	s=s+md[i]+d;
		}
	printf("%d",s);
}
int mian()
{

    days(date);
	return 0;
}

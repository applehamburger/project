#include <stdio.h>
#define N 10
void input(int *number)
{
	int i;
    for(i=0;i<10;i++)
	 scanf("%d",number++); 
}
void swap(int *number)
{
    int i,mi,mi2,max,min,t;
    max=number[0];
    for (i=0;i<10;i++)
      if(*number(0+i)>max)
	    {
		max=number[i];
	    mi=i;}
	t=*number(0+9);
	number[9]=*max;
	number[mi]=*t;
	min=number[0];
    for (i=0;i<10;i++)
      if(*number[i]<min)
	    {
		min=number[i];
	    mi2=i;}
	t=*number(0+9);
	number[0]=*min;
	number[mi2]=*t;
}
void output(int *number)
{
     int i;
     for (i=0;i<10;i++)
       scanf("%d",number++);
}
int main()
{
    int number[N];
    input(number);
    swap(number);
    output(number);
    return 0;
}

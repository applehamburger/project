#include <stdio.h>
int main ()
{
	int i=100,a,b,c,d;
	while(i<=999)
	{a=i/100;
	b=i/10%10;
	c=i%10;
	d=a*a*a+b*b*b+c*c*c;
	if (d==i)
	{
	printf("%d\n",d);}
	i++;
	}
	return 0;
}

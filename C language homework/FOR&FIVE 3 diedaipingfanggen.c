#include <stdio.h>
#include <math.h>
int main()
{
	double x0,x1,b;
	float a;
	scanf("%f",&a);
	x0=a/4.0;
	x1=1.0/2*(x0+a/x0);
	b=(x1-x0);
	while (fabs(b)>=1.0/100000)
	  {
	  x0=x1; 
	  x1=1/2.0*(x0+a/x0);
	  b=(x1-x0);
      }
	  printf("%.5f",x1);
	return 0;
}

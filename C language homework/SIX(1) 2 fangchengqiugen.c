#include <stdio.h>
#include <math.h>
 void root1(float a,float b,float c);
 void root2(float a,float b,float c);
 void root3(float a,float b,float c);
 int main()
 {
 	float a,b,c,d,x1,x2;
 	scanf("%f %f %f",&a,&b,&c);
 	d=b*b-4*a*c;
 	if(fabs(d)<1e-6) 
 	  {
	   root1(a,b,c);
	   }
 	else if(d>0)
 	  {
	   root2(a,b,c);
	   }
 	else if(d<0)
 	  {
	   root3(a,b,c);
 	   }
 	return 0;
 }
  void root1(float a,float b,float c)
 {
 	float x1;
 	x1=-b/2/a;
 	printf("%.2f",x1);
 }
 void root2(float a,float b,float c)
 {
 	float x1,x2;
 	x1=(-b+sqrt(b*b-4*a*c))/2/a;
    x2=(-b-sqrt(b*b-4*a*c))/2/a;
	printf("%.2f %.2f",x1,x2);}	
 
 void root3(float a,float b,float c)
 {
 	float x1,x2;
 	x1=sqrt(-b*b+4*a*c)/2/a;
 	x2=sqrt(-b*b+4*a*c)/2/a;
 	printf("%.2f+%.2fi %.2f-%.2fi",-b/2/a,x1,-b/2/a,x2);
 }
 
 
 
 
 
 

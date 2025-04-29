#include <stdio.h>
int main ()
{
	int j,m,x;
	for(j=0;j<=20;j++) 
	{
	   for(m=0;m<=33;m++)
	 {
		     for(x=0;x<=300;x++)
	    {      if(x%3==0)
		         if(j*5+m*3+x/3==100 && j+m+x==100) 
                   printf("%d %d %d\n",j,m,x);	
	    }
     }
    }
	return 0;
}

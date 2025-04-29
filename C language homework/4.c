#include <stdio.h>
int main ()
{
	int i,j,sum;
	for(i=2;i<=1000;i++)
   {sum=0;
   for(j=1;j<i;j++)
    if (i%j==0)
    sum=sum+j;
	if (sum==i)
	{printf("%d:its factors are ",i);
	for(j=1;j<i;j++)
    if (i%j==0)
	 printf("%d ",j);
	 printf("\n");
		}	
   }
   return 0;
}

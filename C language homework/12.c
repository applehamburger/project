#include <stdio.h>
int main()
{
	int a[10];
	int i,j,h,t;
	for (i=0;i<10;i++)
	{scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	 {
	 for (j=i+1;j<10;j++)
	  {
	  if(a[i]>a[j]&&j==9)
	   for(h=i-1;h>=0;h--)
	    {
		  if(a[i]>a[h]&&h==0)
	      printf("max=%d, pos=%d\n",a[i],i+1);
		  }
		  }
	}
	for(i=0;i<10;i++)
	 for (j=i+1;j<10;j++)
	  if(a[i]<a[j]&&j==9)
	   {
	   for(h=i-1;h>=0;h--)
	     if(a[i]<a[h]&&h==0)      
	     printf("min=%d, pos=%d\n",a[i],i+1);
		 break;}
	return 0;
}

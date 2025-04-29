#include <stdio.h>
int main ()
{
	int a[20],x,i;
	for(i=1;i<=15;i++)
	  scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=1;i<=15;i++)
	  if(x>a[8])
	    {for(i=1;i<8;i++)
	    	if(x==a[i])
	    	  printf("%d",i);
	    	  break;
	    	
		}
	  else 
	    {for(i=8;i<=15;i++)
	    	if(x==a[i])
	    	  {
			  printf("%d",i);
	    	  break;};
	  else if(i!=a[i])
	    	{
			printf("ÎÞ´ËÊý");
		    break;}
	break;
		}
	return 0;
 } 

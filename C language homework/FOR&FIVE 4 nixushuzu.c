#include <stdio.h>
int main ()
{
	int n,i,j,a[1005],t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	j=n;   
	for(i=1;i<j;i++&&j--)  
	
	  if (i!=j)    
	  {
		t=a[j];a[j]=a[i];a[i]=t;
		
		}
	
    for(i=1;i<=n;i++)
	   printf("%d ",a[i]);
	return 0;
}

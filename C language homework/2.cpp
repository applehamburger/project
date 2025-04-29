#include <stdio.h>
int main ()
{
	int a[100005]={0},i,n;
	scanf("%d",&n);
	for (i=2;i<=n;i++)
	 {int j;
	 for (j=2;j<=n;j++)
	   if (i*j<=n)
	     a[i*j]=i*j;
	 }
	for (i=2;i<=n;i++)
	 if(a[i]==0)
	
	   printf("%d ",i);
	return 0;
	
}

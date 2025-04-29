#include <stdio.h>
int main ()
{
	int a[20],x,n,i,t;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d ",&a[i]);
	scanf("%d",&x);
	for(i=n-1;i>=0;i--)
	{if(x<a[i])
	{a[i+1]=a[i];}
	else
	break;}
	 a[i+1]=x;
	}
	for (i=0;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}

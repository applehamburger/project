#include <stdio.h>
int main ()
{
	int n,i,a[100001],j;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{a[i]=i;
	for(j=i+1;j<n;j++)
	{
	if (j%i!=0)
	printf("%d ",a[j]);
	}
    }

	
	return 0;
	
	
}

#include <stdio.h>
int main ()
{
	int n,j,i,a[n][n];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
	for (j=1;j<=i;j++)
	{
	a[i][1]=1;
	a[i][i]=1;
	a[i][j]=a[i-1][j]+a[i-1][j-1];}
	}
	
	for (i=1;i<=n;i++)
	{
	for (j=1;j<=i;j++)
	{
	printf("%d ",a[i][j]);
	}
	printf("\n");
	}
	return 0;
}

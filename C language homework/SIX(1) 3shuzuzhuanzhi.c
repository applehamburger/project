#include <stdio.h>
void transpose(int a[3][3]);
int main ()
{
	int a[3][3],i,j;
	for (i=0;i<3;i++)
	for (j=0;j<3;j++)
	scanf("%d",&a[i][j]);
	transpose(a);
	return 0;
}
void transpose(int a[3][3])
{
	int i,j,t;
	for (i=0;i<3;i++)
	for (j=i+1;j<3;j++)
	{
	t=a[i][j];a[i][j]=a[j][i];a[j][i]=t;}
	for (i=0;i<3;i++)
	{
	for (j=0;j<3;j++)
	printf("%d ",a[i][j]);
	printf("\n");
}
}

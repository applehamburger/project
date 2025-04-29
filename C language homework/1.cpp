#include <stdio.h>
int main()
{
	int i,j,n;
	int a[100005]={0};	
	scanf("%d",&n);
	for(i=2;i<n;i++)
	if(a[i]==0)
	  {for(j=2;i*j<n;j++)
	     if(a[i*j]==0) a[i*j]=1;
	  }
	for(i=2;i<n;i++)
	if(a[i]==0) printf("%d ",i);
    return 0;
 } 

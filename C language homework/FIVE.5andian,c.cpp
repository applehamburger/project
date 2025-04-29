#include <stdio.h>
int main ()
{
	int i,j,m,n,A[20][20],flag,b,max,maxj;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)
	 scanf("%d",&A[i][j]);
	for(i=1;i<=n;i++)
	 {
	 	max=A[i][1];maxj=0;
	 	for(j=1;j<=m;j++)
	 	  if(A[i][j]>max)
	 	  {
	 	  	max=A[i][j];
	 	  	maxj=j;
		   }
		for(b=1,flag=1;b<=n&&flag;b++)
		 if (max>A[b][maxj])
		  flag=0;
		if(flag==1)
		 {
		 	printf("A[%d][%d]=%d是鞍点",i,maxj,max);
		 	break;
			}   
	 }
	if(flag==0)
	printf("没有鞍点"); 
	
	
	return 0;
}

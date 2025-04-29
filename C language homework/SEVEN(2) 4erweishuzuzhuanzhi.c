#include <stdio.h>
#define N 3
void inputmatrix(int *p)
{
    int i,j;
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	    {
		scanf("%d",&p+i*3+j);
		}
}
void transpose(int *p)
{ 
    int i,j,t;
    for(i=0;i<3;i++)
	   for(j=i;j<3;j++) 
	    {
		t=*(p+i*3+j);
		*(p+i*3+j)=*(p+i+j*3);
	    *(p+i+j*3)=t;}
}
void printmatrix(int *p)
{
	int i,j;
	for(i=0;i<3;i++)
	   {
	   for(j=0;j<3;j++)
	   {
		 printf("%d ",*(p+i*3+j));
       }
       printf("\n");}
}
int main()
{
    int s[N][N], *p;
    p = &s[0][0];
    inputmatrix(p);
    transpose(p);
    printmatrix(p);
    return 0;
}

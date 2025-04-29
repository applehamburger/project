#include <stdio.h>
#define N 5 
typedef struct studentinfo
{
	char num[15];
	char name[10];
	int score[3];
	
}studentinfo;
void input(studentinfo s[])
{
	int i;
	for(i=0,i<N;i++;)
	  {
	  	scanf("%s%s%d",&studentinfo.num,studentinfo.name,&studentinfo.score);
	  }
}
void print(studentinfo s[])
{
	int i;
	for(i=0,i<N;i++;)
	  {
	  	printf("%-13s%-9s%4d",studentinfo.num,studentinfo.name,studentinfo.score);
	  }
}
int main()
{
	struct studentinfor s[N],*p=s;
	input(p); 
	print(P);
	return 0;
}

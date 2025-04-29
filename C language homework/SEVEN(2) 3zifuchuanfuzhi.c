#include <stdio.h>
void mcopy(char*p1,char*p2,int m);
int main()
{
	char str1[1000],str2[1000];
	int m;
	gets(str1);
	scanf("%d",&m);
	mcopy(str1,str2,m);
	printf("%s",str2);
}
void mcopy(char*p1,char*p2,int m)
{
	int i;
	for(i=0;i<m-1;i++) p1++; 
	while(*p2++=*p1++);
	*p2='\0'; 	
}

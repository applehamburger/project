#include <stdio.h>
int slength(char*p);
int main()
{
	char s[1000];
	gets(s);
	printf("%d",slength(s));
 } 
 int slength(char*p)
 {
 	int i=0,j=0;
 	for(i=0;;i++)
 	{
	 if(*(p+i)!='\0')
	   j++;
	 else break;
	 }
	return(j);
 }

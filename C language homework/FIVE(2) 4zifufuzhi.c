#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[20],s2[20];
	int i;
	gets(s2);
	for(i=1;s2[i-1]!=0&&i<=20;i++)
	  s1[i-1]=s2[i-1];
	puts(s1);
	return 0;
 } 

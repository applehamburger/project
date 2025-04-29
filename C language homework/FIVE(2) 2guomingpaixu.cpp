#include <stdio.h>
#include <string.h>
int main()
{
	char s[10][21];
	int i,j,t;
	for(i=0;i<10;i++)
	  gets(s[i]);
	for(i=0;i<10;i++)
	  {
	  for(j=i+1;j<10&&s[i][j]!=0;j++)
	   if(s[i][0]>s[j][0])
	     {t=s[j][20];s[j][20]=s[i][20];s[i][20]=t;}
       }
    for(i=0;i<10;i++)  
    puts(s[i]);
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	char s[10][21],b[21];
	int i,j;
	for(i=0;i<10;i++)
	  gets(s[i]);
	for(i=0;i<10;i++)
	  {
	  for(j=i+1;j<10;j++)
	   if(strcmp(s[i],s[j])>0)
	    {
	    	strcpy(b,s[i]);
	    	strcpy(s[i],s[j]);
	    	strcpy(s[j],b);
		}
       }
    for(i=0;i<10;i++)  
    puts(s[i]);
	return 0;
}

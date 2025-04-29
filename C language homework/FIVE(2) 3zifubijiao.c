#include <stdio.h>
#include <string.h>
int main()
{
	char s1[21],s2[21];
	int i;
	gets(s1);
	gets(s2);
	for(i=0;i<20;i++)
	 {
	  if(s1[i]!=s2[i])
	   {
	   printf("%d",s1[i]-s2[i]);
	   break;}
	  else if(s1[i]=s2[i]&&s2[i+1]==0&&s1[i+1]==0)
	   {
	   printf("0");
	   break;
	   }
      }
	return 0;
 } 

#include <stdio.h>
#include <string.h>
void maxword(char s[101]);
int main ()
{
	char s[101];
	gets(s);
	maxword(s);
	return 0;	
 } 
 void maxword(char s[101])
 {
 	int i,x=0,y,max=0;
 int m,n;
 int l=strlen(s);
 for(i=0;i<=l;i++)
 {
  if(s[i]==' '||s[i]=='\0')
  {
   y=i-1;
   if((y-x+1)>max)
   {
    max=y-x+1;
    m=x;n=y;
   }
   x=i+1;
  }
 }
 for(i=m;i<=n;i++)
 {
  printf("%c",s[i]);
 }
}
 

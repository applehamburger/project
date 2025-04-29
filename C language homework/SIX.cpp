#include<stdio.h>
#include<string.h>
void rev_str(char s[100]);
int main()
{
 char s[100];
 gets(s);
 rev_str(s);
 puts(s);
 return 0;
 } 
 void rev_str(char s[100])
 {
  int i,j;
  char t;
  j=strlen(s)-1;
  for(i=0;i<j;i++,j--)
  {
   t=s[i];
   s[i]=s[j];
   s
   [j]=t;
 }
 }

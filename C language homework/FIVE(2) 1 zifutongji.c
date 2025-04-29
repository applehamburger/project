#include <stdio.h>
#include <string.h>
int main()
{
 char s[3][100];
 int i,j,a1=0,a2=0,a3=0,a4=0,a5=0;
 for(i=0;i<3;i++)
   gets(s[i]);
 for(i=0;i<3;i++)
 {   
  for(j=0;s[i][j]!=0;j++) 
 {   if(s[i][j]!='\0')
    {
     if('A'<=s[i][j]&&s[i][j]<='Z')
  a1++;
  else if('a'<=s[i][j]&&s[i][j]<='z')
  a2++;
  else if('0'<=s[i][j]&&s[i][j]<='9')
  a3++;
  else if(s[i][j]==' ')
  a4++;
  else
  a5++;
}
 }
 }
 printf("%d %d %d %d %d",a1,a2,a3,a4,a5);
 return 0;
}

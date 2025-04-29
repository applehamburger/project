#include <stdio.h>  
int day(int y,int m,int d);
int main()
{
 int y,m,d;
 int x;
 scanf("%d %d %d",&y,&m,&d);
 x=day(y,m,d);
 printf("%d",x);
 return 0;
}

int day(int y,int m,int d)
 {
  int sum;
  switch(m)
  {
   case 12:sum=334;break;
   case 11:sum=303;break;
   case 10:sum=273;break;
   case 9:sum=243;break;
   case 8:sum=212;break;
   case 7:sum=181;break;
   case 6:sum=151;break;
   case 5:sum=120;break;
   case 4:sum=90;break;
   case 3:sum=59;break;
   case 2:sum=31;break;
   case 1:sum=0;break;
  }
  if(y%400==0&&y||y%4==0&&y%100!=0)
  {
   if(m>2)
   {
    sum++;
   }
  }
  return sum+d; 
 }

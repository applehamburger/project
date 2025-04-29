#include<stdio.h>
int calcGCG(int a,int b); 
int calcLCM(int a,int b);
int main()
{
 int a,b;
 scanf("%d %d",&a,&b);
 printf("%d %d",calcGCG(a,b),calcLCM(a,b));
 return 0;
}
int calcLCM(int a,int b)
{
 int i;
 for(i=a;;i++)
 {
  if(i%a==0&&i%b==0)
  return i;
 }
}
int calcGCG(int a,int b)
{
 int i;
 for(i=a;;i--)
 {
  if(a%i==0&&b%i==0)
  return i;
 }
}

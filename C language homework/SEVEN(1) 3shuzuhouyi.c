#include <stdio.h>
#define N 10
void input(int *number);
void swap(int *number);
void output(int *number);
int main()
{
    int number[N];
    input(number);
    swap(number);
    output(number);
    return 0;
}
void input(int *number)
{
 int *p;
 for(p=number;p<number+10;p++)
 {
  scanf("%d",p);
 }
}
void swap(int *number)
{
 int temp,min=*number,max=*(number+10);
 int *x,*y,*p,*i;
 for(p=number;p<number+10;p++)
 {
  if(*p>max)
  {
   max=*p;
   x=p;
  }
  
 }
 *x=*(number+9);
 *(number+9)=max;
 for(i=number;i<number+10;i++)
 {
  if(*i<min)
  {
   min=*i;
   y=i;
  }
  
 }
 *y=*number;
 *number=min;
}
void output(int *number)
{
 int *q;
    for(q=number;q<number+10;q++)
 {
  printf("%d ",*q);
 }
}


#include<stdio.h>
int main()
{
 int m = 0;
 int n = 0;
 int c = 0;
 scanf("%d %d", &m, &n);
    int a = m*n;
 
 while (c = m % n)
 {
  m = n;
  n = c;
 }
 
 printf("%d %d\n", n, a/n);
 
   
 return 0;
}



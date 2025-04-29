#include <stdio.h>
int main()
{
 int m = 0;
 int i = 0;
 int j = 0;
 double sum = 0.0;
 scanf("%d", &m);
 for (i = 1; i <= m; i++)
 {
  double ret = 1;
  for (j = 1; j <= i; j++)
  {
   ret = ret*j;
   
  }
  sum = sum + ret;
   
 }
 printf("%.5e\n", sum);
 return 0;
}



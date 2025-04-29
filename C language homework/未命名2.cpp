#include <stdio.h>
#include <stdlib.h>
int main() {
 int i, j ,m, n, p, q,x;
 scanf("%d",&x);
 for(i=1;i<=x;i++){
  for(j=x-i;j>0;j--){
   printf(" ");
  }
  for(m=1;m<=2*i-1;m++){
   printf("*");
  }
  printf("\n");
 }
 for(n=1;n<=x-1;n++){
  for(p=0;p<n;p++){
   printf(" ");
  }
  for(q=2*x-1-2*n;q>0;q--){
   printf("*");
  }
  printf("\n");
 }
 return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
 int a[3][3],i,m,j,sum=0;
 for(i=0;i<3;i++){
  scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
 }
 for(m=0;m<3;m++){
  for(j=0;j<3;j++){
   if(m==j){
    sum=sum+a[m][j];
   }
  }
 }
 printf("%d",sum);
 return 0;
}



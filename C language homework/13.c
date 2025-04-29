#include<stdio.h>
void Mystrncpy(char * a, char *b, int m, int n );
int main()
{
    int m,n;
	char a[999];
	char b[999];
	gets(a);
	scanf ("%d %d",&m,&n);
    Mystrncpy(a[0],b[0],m,n);
    printf("%s",b[999]);
    return 0;
}
void Mystrncpy(char * a, char *b, int m, int n )
{
     int i;
     *a=*(a+m);
     for(i=m;i<n;a++)
     {
	 *b=*a;
     }
}


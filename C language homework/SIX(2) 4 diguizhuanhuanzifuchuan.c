  #include <stdio.h>
#define MAX_LEN 11
int pos = 0;
void convert(int n, char str[])
{
    int x=0;
    x=n%10;
    n=n/10;
    if(n>0)
    {convert(n,str);}
    str[pos]=x+48;
    pos++;
}
int main()
{
    int n;
    char str[MAX_LEN];
    scanf("%d", &n);
    convert(n, str);
    printf("%s\n", str);
    return 0;
}

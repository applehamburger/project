#include <stdio.h>
#include <string.h>
#define N 81
void swap(char *p1, char *p2)
{
	char temp[81],*t=temp;
	while(*t=*p1!='\0')
	{t++;p1++;};
	while(*p1=*p2!='\0')
	{p1++;p2++;};
	while(*p2=*t!='\0')
	{p2++;t++;};
     ///程序填空，请将该函数填写完整
}
int main()
{
    char str1[N], str2[N], str3[N];
    gets(str1);
    gets(str2);
    gets(str3);
    if(strcmp(str1, str2) > 0)
        swap(str1, str2);
    if(strcmp(str1, str3) > 0)
        swap(str1, str3);
    if(strcmp(str2, str3) > 0)
        swap(str2, str3);
    printf("%s\n%s\n%s\n", str1, str2, str3);
    return 0;
}

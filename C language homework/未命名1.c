#include <stdio.h>
int main()
{
	int i=1,j=0;
	float a,s=0,p;
	while(i<=3)
	{
	i++;
	while(a!=-1)
	{
		scanf("%f",&a);
		if (a=-1) break;
		s=s+a;
		j++;
	}
	p=s/j;
	printf("%d %.2f",i,p);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
int read(int num[], char str[]);
int sortbyno(int num[], char str[][11]);
int search(int x, int arr[]);
int main()
{
    int no[10], i, key, findpos;
    char name[10][11] = {0};
    for (i = 0; i <= 9; i++)
    {
        read(&no[i], name[i]);
    }
    scanf("%d", &key);
    sortbyno(no, name);
    for (i = 0; i <= 9; i++)
    {
        printf("%d %s\n", no[i], name[i]);
    }
    findpos = search(key, no);
    if (findpos == -1)
    {
        printf("没有匹配的职工");
    }
    else
    {
        printf("%s", name[findpos]);
    }
}
int read(int num[], char str[])
{
    scanf("%s", str);
    scanf("%d", num);
}
int sortbyno(int num[], char str[][11])
{
    int i, min, pointer, changetemp;
    char strtemp[21] = {0};
    for (i = 0; i <= 9; ++i)
    {
        min = i;
        for (pointer = i + 1; pointer <= 9; ++pointer)
        {
            if (num[min] > num[pointer])
            {
                min = pointer;
            }
        }
        if (min != i)
        {
            changetemp = num[i];
                strcpy(strtemp, str[i]);
            num[i] = num[min];
                strcpy(str[i], str[min]);
            num[min] = changetemp; 
                strcpy(str[min], strtemp);
        }
    }
}
int search(int x, int arr[])
{
    int low=0, mid, high=9, pos = -1;
    while (high >= low)
    {
        mid = (high + low)/2;
        if (x > arr[mid])
        {
            low = mid + 1;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            pos = mid;
            break;
        }
    }
    return (pos);
}

#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct Student)
struct Student
{
    int num;
    float score;
    struct Student *next;
};
int n;
struct Student * create();
void print(struct Student * head);
struct Student * del(struct Student * head, int num)
{
    struct Student *pForward = head, *pBack = head;
    int isFirstRound = 1; // 该变量用于判断循环是否在执行第一轮
    while (pForward->num != num){ // 判断走前面的指针所指的 是否为待找元素
        if (pForward->next == NULL){ // 判断走前面的指针所指的 是否为末尾元素
            printf("Not Found\n");
            break;
        }
        pBack = pForward;
        pForward = pForward->next;
        isFirstRound = 0; // 如果循环被执行至少一次, 该变量设为0
    }
    pForward = pForward->next;
    if (isFirstRound == 1) return (pForward); // 如果循环没被执行, 说明第一个即为待找元素, 则将开头元素设为第二个
    pBack->next = pForward;
    return (head);
}
int main()
{
    struct Student *head;
    int num;
    head = create();
    scanf("%d", &num);
    head = del(head, num);
    print(head);
    return 0;
}
struct Student * create()
{
    struct Student *head, *p1, *p2;
    n = 0;
    p1 = p2 = (struct Student*)malloc(LEN);
    scanf("%d %f", &p1->num, &p1->score);
    head = NULL;
    while(p1->num != 0)
    {
        n = n + 1;
        if(n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct Student*)malloc(LEN);
        scanf("%d %f", &p1->num, &p1->score);
    }
    p2->next = NULL; 
    return head;  
}
void print(struct Student * head)
{
    struct Student * p;
    p = head;
    if(head != NULL)
    {
        do{
            printf("%d %.1f\n", p->num, p->score);
            p = p->next;
        }while(p != NULL);
    }
}
 

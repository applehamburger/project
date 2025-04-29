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
    int isFirstRound = 1; // �ñ��������ж�ѭ���Ƿ���ִ�е�һ��
    while (pForward->num != num){ // �ж���ǰ���ָ����ָ�� �Ƿ�Ϊ����Ԫ��
        if (pForward->next == NULL){ // �ж���ǰ���ָ����ָ�� �Ƿ�ΪĩβԪ��
            printf("Not Found\n");
            break;
        }
        pBack = pForward;
        pForward = pForward->next;
        isFirstRound = 0; // ���ѭ����ִ������һ��, �ñ�����Ϊ0
    }
    pForward = pForward->next;
    if (isFirstRound == 1) return (pForward); // ���ѭ��û��ִ��, ˵����һ����Ϊ����Ԫ��, �򽫿�ͷԪ����Ϊ�ڶ���
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
 

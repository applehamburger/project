#include <stdio.h>
#include <malloc.h>          
#define LEN sizeof(struct Student)
struct Student
{
    int num;
    float score;
    struct Student *next;
};
void print(struct Student * head);
struct Student * insert(struct Student * head, struct Student * stud) // �����������
{
    stud->next = head;
    // ����Ϊѡ������
    struct Student *origin = stud, *maxPos, *searcher;
    int temp;
    float tempf; // ��Ҫ�������ѭ������, ���԰�origin�����i, searcher�����j�Ա������
    while (origin->next != NULL){
        maxPos = origin;
        searcher = origin->next;
        while (1){
            if (searcher->num < maxPos->num) maxPos = searcher;
            if (searcher->next == NULL) break; // ������������β�����ж�ѧ�Ŵ�С��������ѭ��
            else searcher = searcher->next; // �ȼ���j++
        }
        if(origin != maxPos){
            // ����ѧ��
            temp = origin->num;
            origin->num = maxPos->num;
            maxPos->num = temp;
            // ��������
            tempf = origin->score;
            origin->score = maxPos->score;
            maxPos->score = tempf;
        }
        origin = origin->next; // �ȼ���i++
    }
    return (stud);
}
int main()
{
    struct Student *head = NULL, *stud;
    int num;
    float score;
    while(1)
    {
        scanf("%d %f", &num, &score);
        if(num == 0)
            break;
        stud = (struct Student*)malloc(LEN);
        stud->num = num;
        stud->score = score;
        head = insert(head, stud);
    }
    print(head);
    return 0;
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
 

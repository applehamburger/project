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
struct Student * insert(struct Student * head, struct Student * stud) // 倒序插入链节
{
    stud->next = head;
    // 以下为选择法排序
    struct Student *origin = stud, *maxPos, *searcher;
    int temp;
    float tempf; // 若要理解以下循环代码, 可以把origin想象成i, searcher想象成j以便于理解
    while (origin->next != NULL){
        maxPos = origin;
        searcher = origin->next;
        while (1){
            if (searcher->num < maxPos->num) maxPos = searcher;
            if (searcher->next == NULL) break; // 如果遇到链表结尾，先判断学号大小，再跳出循环
            else searcher = searcher->next; // 等价于j++
        }
        if(origin != maxPos){
            // 交换学号
            temp = origin->num;
            origin->num = maxPos->num;
            maxPos->num = temp;
            // 交换分数
            tempf = origin->score;
            origin->score = maxPos->score;
            maxPos->score = tempf;
        }
        origin = origin->next; // 等价于i++
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
 

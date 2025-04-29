#include <stdio.h>
#include <stdlib.h>
 
#define LEN sizeof(struct Element) 
struct Element
{
    int serial;
    struct Element *next; 
};
 
int main(){
    struct Element *deliver(int), *pointer, *start;
    int amount , outCount = 0, count = 0;
    register int i = 0;
    scanf("%d", &amount);
    start = pointer = deliver(amount);
    while (outCount < amount - 1)// 只剩一人时跳出循环
      {
        if (pointer->serial != 0) count++;
        if (count == 3){ // 数到3，就淘汰
            pointer->serial = 0; // 将退出圈子的人的序号记为0
            count = 0;
            outCount++;
        } 
 
        i++;
        if (i == amount){
            pointer = start;
            i = 0; // 遇到队尾，从头继续数
            continue;
        }
        pointer = pointer->next;
    }
    pointer = start;
    while(pointer->serial == 0){
        pointer = pointer->next;
    } // 遇到非0序号，则此人为最后留下的人，跳出循环
    printf("%d", pointer->serial);
    return 0;
}
 
struct Element *deliver(int n){
 
    //  为什么要加 "struct Element" 前缀? 因为 "*deliver" 是一个指针函数。当指针将要向后移动一个单位时，它讲要做的事情实际上，是将自己在内存里的位置，往后移动特定数量的bits，这样才可以通过准确达到下一个元素的位置。*/
    struct Element *pBack, *pForward, *head = NULL;
    register int j = 0;
    do{
        if (j == 0) pForward = (struct Element*)malloc(LEN);
        /* (struct Element*)用于限制数据大小，struct Element用于声明数据类型 */
        if (j == 0) head = pForward;
        pBack = pForward;
        pBack->serial = j + 1; // Serial number starts from " 1 ". 序号从“ 1 ”开始
        if (j != n - 1)
		{
            pForward = (struct Element*)malloc(LEN);
            pBack->next = pForward;
        }
        else pBack->next = NULL;
        j++;
    }while(j < n);
    return (head);
}
 

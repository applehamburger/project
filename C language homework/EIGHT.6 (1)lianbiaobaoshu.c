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
    while (outCount < amount - 1)// ֻʣһ��ʱ����ѭ��
      {
        if (pointer->serial != 0) count++;
        if (count == 3){ // ����3������̭
            pointer->serial = 0; // ���˳�Ȧ�ӵ��˵���ż�Ϊ0
            count = 0;
            outCount++;
        } 
 
        i++;
        if (i == amount){
            pointer = start;
            i = 0; // ������β����ͷ������
            continue;
        }
        pointer = pointer->next;
    }
    pointer = start;
    while(pointer->serial == 0){
        pointer = pointer->next;
    } // ������0��ţ������Ϊ������µ��ˣ�����ѭ��
    printf("%d", pointer->serial);
    return 0;
}
 
struct Element *deliver(int n){
 
    //  ΪʲôҪ�� "struct Element" ǰ׺? ��Ϊ "*deliver" ��һ��ָ�뺯������ָ�뽫Ҫ����ƶ�һ����λʱ������Ҫ��������ʵ���ϣ��ǽ��Լ����ڴ����λ�ã������ƶ��ض�������bits�������ſ���ͨ��׼ȷ�ﵽ��һ��Ԫ�ص�λ�á�*/
    struct Element *pBack, *pForward, *head = NULL;
    register int j = 0;
    do{
        if (j == 0) pForward = (struct Element*)malloc(LEN);
        /* (struct Element*)�����������ݴ�С��struct Element���������������� */
        if (j == 0) head = pForward;
        pBack = pForward;
        pBack->serial = j + 1; // Serial number starts from " 1 ". ��Ŵӡ� 1 ����ʼ
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
 

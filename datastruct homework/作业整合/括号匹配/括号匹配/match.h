#pragma once
#include <iostream>
using namespace std;

#define ElemType char
#define MAXSIZE 100

typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
} StackNode, * LinkStack;

enum Status {
    OK,     // ִ�гɹ�
    ERROR   // ִ��ʧ��
};

// ��ʼ��ջ
Status CreateStack(LinkStack& S);

// ��ջ����
Status Push(LinkStack& S, ElemType e);


// ��ջ����
Status Pop(LinkStack& S, ElemType& e);

// ��ȡջ��Ԫ��
ElemType GetTop(LinkStack S);

Status Traverse(LinkStack S);

Status ClearStack(LinkStack& S);

Status DestroyStack(LinkStack& S);

bool StackEmpty(LinkStack S);

Status Matching(LinkStack S);

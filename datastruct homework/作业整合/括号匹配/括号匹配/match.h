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
    OK,     // 执行成功
    ERROR   // 执行失败
};

// 初始化栈
Status CreateStack(LinkStack& S);

// 入栈操作
Status Push(LinkStack& S, ElemType e);


// 出栈操作
Status Pop(LinkStack& S, ElemType& e);

// 获取栈顶元素
ElemType GetTop(LinkStack S);

Status Traverse(LinkStack S);

Status ClearStack(LinkStack& S);

Status DestroyStack(LinkStack& S);

bool StackEmpty(LinkStack S);

Status Matching(LinkStack S);

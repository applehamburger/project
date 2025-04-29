#pragma once
#include<iostream>
using namespace std;


typedef int ElemType;
typedef int Status;
//顺序栈存储空间的初始分配量
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define NULL 0
typedef struct
{
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;


//创建char类型的链栈
typedef char Status_;
typedef char SElemType;


typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

//顺序栈的初始化
Status InitStack(SqStack& S);
//顺序栈的入栈
Status Push(SqStack& S, ElemType e);
//遍历栈
void StackTraverse(SqStack& S);
//判断是否栈满
Status StackFull(SqStack S);
//顺序栈的出栈
Status Pop(SqStack& S, ElemType& e);
//取栈顶元素
Status GetTop(SqStack S);
//判断栈是否为空
bool StackEmpty(SqStack S);
//清空栈
Status ClearStack(SqStack& S);
//销毁栈
Status DestroyStack(SqStack& S);
//实现数值转换
//void conversion(SqStack& S,int N, int n);

//进行计算
int Operate(ElemType a, ElemType b, SElemType ch);

//初始化链栈
Status_ InitStack(LinkStack& S);

//创建链栈 链栈的入栈
Status_ Push(LinkStack& S, SElemType e);

//遍历链栈里的元素
void TraverseStack(LinkStack S);

//判断是否是运算符
bool In(SElemType ch);

//链栈的出栈
Status_ Pop(LinkStack& S, SElemType& e);

//取栈顶元素
SElemType GetTop(LinkStack& S);
//bool Gettop(LinkStack& S, SElemType& e);

//判断栈空
Status_ StackEmpty(LinkStack& S);

//清空栈
Status_ ClearStack(LinkStack& S);

//销毁栈
Status_ DestroyStack(LinkStack& S);

//比较优先级
Status_ Compare(SElemType op, SElemType ch);

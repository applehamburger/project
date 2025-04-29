#pragma once
#include<iostream>
using namespace std;


typedef int ElemType;
typedef int Status;
//˳��ջ�洢�ռ�ĳ�ʼ������
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


//����char���͵���ջ
typedef char Status_;
typedef char SElemType;


typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack& S);
//˳��ջ����ջ
Status Push(SqStack& S, ElemType e);
//����ջ
void StackTraverse(SqStack& S);
//�ж��Ƿ�ջ��
Status StackFull(SqStack S);
//˳��ջ�ĳ�ջ
Status Pop(SqStack& S, ElemType& e);
//ȡջ��Ԫ��
Status GetTop(SqStack S);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S);
//���ջ
Status ClearStack(SqStack& S);
//����ջ
Status DestroyStack(SqStack& S);
//ʵ����ֵת��
//void conversion(SqStack& S,int N, int n);

//���м���
int Operate(ElemType a, ElemType b, SElemType ch);

//��ʼ����ջ
Status_ InitStack(LinkStack& S);

//������ջ ��ջ����ջ
Status_ Push(LinkStack& S, SElemType e);

//������ջ���Ԫ��
void TraverseStack(LinkStack S);

//�ж��Ƿ��������
bool In(SElemType ch);

//��ջ�ĳ�ջ
Status_ Pop(LinkStack& S, SElemType& e);

//ȡջ��Ԫ��
SElemType GetTop(LinkStack& S);
//bool Gettop(LinkStack& S, SElemType& e);

//�ж�ջ��
Status_ StackEmpty(LinkStack& S);

//���ջ
Status_ ClearStack(LinkStack& S);

//����ջ
Status_ DestroyStack(LinkStack& S);

//�Ƚ����ȼ�
Status_ Compare(SElemType op, SElemType ch);

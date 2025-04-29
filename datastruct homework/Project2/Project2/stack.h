#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define ElemType int
#define OK 1
#define ERROR 0
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;

//��ʼ��˳��ջ
void InitStack(SqStack& S);

//˳��ջ��ջ
void Push(SqStack& S, ElemType e);

//�ж�ջ��
bool StackEmpty(SqStack& S);

//�ж�ջ��
bool StackFull(SqStack& S);

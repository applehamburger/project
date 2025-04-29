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



//初始化顺序栈

void InitStack(SqStack& S);

​

//顺序栈入栈





//判断栈空

//bool StackEmpty(SqStack& S);



//判断栈满

bool StackFull(SqStack& S);



//顺序栈出栈

void  Pop(SqStack& S, ElemType e);
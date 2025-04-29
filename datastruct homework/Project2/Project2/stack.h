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

//≥ı ºªØÀ≥–Ú’ª
void InitStack(SqStack& S);

//À≥–Ú’ª»Î’ª
void Push(SqStack& S, ElemType e);

//≈–∂œ’ªø’
bool StackEmpty(SqStack& S);

//≈–∂œ’ª¬˙
bool StackFull(SqStack& S);

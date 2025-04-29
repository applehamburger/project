#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
}Sqlist;
Status InitList(Sqlist& L);
Status DestroyList(Sqlist& L);
Status ClearList(Sqlist& L);
void ListTraverse(const Sqlist& L);
Status GetElem(Sqlist L, int i, ElemType & e);
int LocateElem(Sqlist L, ElemType e);
Status ListInsert(Sqlist& L, int i, ElemType e);
Status ListDelete(Sqlist& L, int i, ElemType& e);
int ListLength(const Sqlist& L);
bool ListEmpty(const Sqlist& L);
void Lunion(Sqlist& La, Sqlist Lb);
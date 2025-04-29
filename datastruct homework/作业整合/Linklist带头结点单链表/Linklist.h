#pragma once
#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define NULL 0
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode, * LinkList;


Status InitList(LinkList& L);
void CreateList_H(LinkList& L, int n);
void CreateList_R(LinkList& L, int n);
void ListTraverse(const LinkList& L);
Status GetElem(LinkList L, int i, ElemType& e);
int LocateElem(LinkList L, ElemType e);
Status ListInsert(LinkList& L, int i, ElemType e);
Status ListDelete(LinkList& L, int i, ElemType& e);
bool ListEmpty(const LinkList& L);
int ListLength(const LinkList& L);
Status DestroyList(LinkList& L);
void ClearList(LinkList& L);
//LinkList Find(LinkList L, ElemType x);
//LinkList Locate(LinkList L, int i);
Status equal(int a, int b);
void Lunion(LinkList& La, LinkList& Lb);

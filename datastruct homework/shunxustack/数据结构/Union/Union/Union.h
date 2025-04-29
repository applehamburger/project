#pragma once
#include<iostream>
using namespace std;
//单链表数据结构定义
#define OK 1
#define ERROR 0
#define NULL 0

typedef char ElemType;
typedef int Status;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;


//初始化
Status InitList(LinkList& La);
//创建单链表
//头插法
void CreateList_H(LinkList& L);
//尾插法
void CreateList_R(LinkList& L);
//遍历单链表
void ListTraverse(const LinkList& L);
//取值
Status GetElem(LinkList L, int i);
//查找
int LocateElem(LinkList L, ElemType e);
//插入
Status ListInsert(LinkList& L, int i, ElemType e);
//表长
int ListLength(LinkList L);
void Union(LinkList& La, LinkList Lb);
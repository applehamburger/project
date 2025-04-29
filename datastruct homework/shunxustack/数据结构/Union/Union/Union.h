#pragma once
#include<iostream>
using namespace std;
//���������ݽṹ����
#define OK 1
#define ERROR 0
#define NULL 0

typedef char ElemType;
typedef int Status;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;


//��ʼ��
Status InitList(LinkList& La);
//����������
//ͷ�巨
void CreateList_H(LinkList& L);
//β�巨
void CreateList_R(LinkList& L);
//����������
void ListTraverse(const LinkList& L);
//ȡֵ
Status GetElem(LinkList L, int i);
//����
int LocateElem(LinkList L, ElemType e);
//����
Status ListInsert(LinkList& L, int i, ElemType e);
//��
int ListLength(LinkList L);
void Union(LinkList& La, LinkList Lb);
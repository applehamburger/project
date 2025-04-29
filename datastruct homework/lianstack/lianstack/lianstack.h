#pragma once
#include<iostream>

using namespace std;

typedef int ElemType;

typedef struct SNode{
	ElemType data;
	SNode* next;

}*LinkStack;

void Init(LinkStack&);//��ʼ��
int Push(LinkStack&, ElemType);//ջ��
int Pop(LinkStack&, ElemType&);//ջ��
int GetTop(LinkStack&, ElemType*);//ȡ��
int IsEmpty(const LinkStack&);//�п�
void Traverse(const LinkStack&);//����
void Clear(LinkStack&);//���
void Destory(LinkStack&);//����
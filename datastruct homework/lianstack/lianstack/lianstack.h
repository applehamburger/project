#pragma once
#include<iostream>

using namespace std;

typedef int ElemType;

typedef struct SNode{
	ElemType data;
	SNode* next;

}*LinkStack;

void Init(LinkStack&);//初始化
int Push(LinkStack&, ElemType);//栈入
int Pop(LinkStack&, ElemType&);//栈出
int GetTop(LinkStack&, ElemType*);//取顶
int IsEmpty(const LinkStack&);//判空
void Traverse(const LinkStack&);//遍历
void Clear(LinkStack&);//清空
void Destory(LinkStack&);//销毁
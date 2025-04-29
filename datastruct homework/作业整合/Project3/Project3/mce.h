#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100   // ����ջ���������
typedef char selemtype;
typedef int elemtype;  // ����ջԪ������

// ����˳��ջ�ṹ��
struct SeqStack {
    elemtype data[MAX_SIZE];  // ջ����
    int top;  // ջ��ָ��
};

// ��ʼ��ջ
void InitStack(SeqStack& opStack);

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SeqStack opStack);

// �ж�ջ�Ƿ�����
bool StackFull(SeqStack opStack);

// ��ջ����
bool Push(SeqStack& opStack, elemtype element);


// ��ջ����
bool Pop(SeqStack& opStack, elemtype& element);

// ��ȡջ��Ԫ��
bool GetTop(SeqStack opStack, elemtype& element);

// ����ջԪ��
void Traverse(SeqStack opStack);

// ���ջ
void ClearStack(SeqStack& opStack);

// ����ջ
void DestroyStack(SeqStack& opStack);

void change(SeqStack& opStack, selemtype ch);

bool In(selemtype ch);
#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100   // ����ջ���������

typedef int elemtype;  // ����ջԪ������
typedef char selemtype;
// ����˳��ջ�ṹ��
struct SeqStack {
    elemtype data[MAX_SIZE];  // ջ����
    int top;  // ջ��ָ��
};

// ��ʼ��ջ
void InitStack(SeqStack& OPND);

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SeqStack stack);

// �ж�ջ�Ƿ�����
bool StackFull(SeqStack stack);

// ��ջ����
bool Push(SeqStack& OPND, elemtype element);


// ��ջ����
bool Pop(SeqStack& OPND, elemtype& element);

// ��ȡջ��Ԫ��
bool GetTop(SeqStack stack, elemtype& element);

//// ����ջԪ��
//void Traverse(SeqStack stack);
//
//// ���ջ
//void ClearStack(SeqStack& stack);
//
//// ����ջ
//void DestroyStack(SeqStack&OPND);

bool EvaluateExpression(SeqStack OPND,selemtype ch);

bool In(selemtype ch);

int  Dooperate(elemtype a, elemtype ch, elemtype b);

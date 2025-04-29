#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100   // ����ջ���������

typedef int elemtype;  // ����ջԪ������

// ����˳��ջ�ṹ��
struct SeqStack {
    elemtype data[MAX_SIZE];  // ջ����
    int top;  // ջ��ָ��
};

// ��ʼ��ջ
void InitStack(SeqStack& stack);

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SeqStack stack);

// �ж�ջ�Ƿ�����
bool StackFull(SeqStack stack);

// ��ջ����
bool Push(SeqStack& stack, elemtype element);


// ��ջ����
bool Pop(SeqStack& stack, elemtype& element);

// ��ȡջ��Ԫ��
bool GetTop(SeqStack stack, elemtype& element);

// ����ջԪ��
void Traverse(SeqStack stack);

// ���ջ
void ClearStack(SeqStack& stack);

// ����ջ
void DestroyStack(SeqStack& stack);
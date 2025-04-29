#include "stack.h"
//��ʼ��˳��ջ
void InitStack(SqStack& S) {
	//����һ����ջ
	S.base = new ElemType[MAXSIZE];
	if (S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	
}

//�ж�ջ��
bool StackEmpty(SqStack& S) {
	if (S.top == S.base)
		return OK;
}
//�ж�ջ��
bool StackFull(SqStack& S) {
	if (S.top - S.base == S.stacksize) 
		return ERROR;
}
//˳��ջ��ջ
void Push(SqStack& S, ElemType e) {
	
	*S.top = e;
	S.top++;
	
}
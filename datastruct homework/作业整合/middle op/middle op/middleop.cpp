#include"middleop.h"

//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack& S)
{//����һ����ջS
	//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	S.base = new ElemType[MAXSIZE];
	//�洢����ʧ��
	if (!S.base)exit(OVERFLOW);
	//top��ʼΪbase����ջ
	S.top = S.base;
	//stacksize��Ϊջ���������MAXSIZE
	S.stacksize = MAXSIZE;
	return OK;
}
//˳��ջ����ջ
Status Push(SqStack& S, ElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	//ջ��
	if (S.top - S.base == S.stacksize)return ERROR;
	//Ԫ��eѹ��ջ����ջ��ָ���1
	*S.top++ = e;
	return OK;
}
//����ջ
void StackTraverse(SqStack& S) {
	ElemType* p = S.base;
	while (p < S.top) {
		cout << *p << " ";
		p++;
	}
}
//�ж��Ƿ�ջ��
Status StackFull(SqStack S) {
	if (S.top - S.base == S.stacksize)
		return OK;
	else return ERROR;
}
//˳��ջ�ĳ�ջ
Status Pop(SqStack& S, ElemType& e)
{//ɾ��S��ջ��Ԫ�أ���e������ֵ
	//ջ��
	if (S.top == S.base) return ERROR;
	//ջ��ָ���1����ջ��Ԫ�ظ���e
	e = *--S.top;
	return e;
}
Status GetTop(SqStack S)
{//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	//ջ�ǿ�
	if (S.top != S.base)
		return *(S.top - 1);
}
Status ClearStack(SqStack& S) {
	if (S.base)S.base = S.top;
	return OK;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S) {
	if (S.base == S.top)return true;
	else return false;
}
//����ջ
Status DestroyStack(SqStack& S) {
	ElemType* p = S.base;
	S.base = S.top = NULL;
	delete[] p;
	S.stacksize = 0;
	return OK;
}
//ʵ����ֵת��
//void conversion(SqStack& S,int N, int n) {
//	ElemType e;
//	while (N) {
//		Push(S, N % n);
//		N = N / n;
//	}
//	while (!StackEmpty(S)) {
//		Pop(S, e);
//		cout << e;
//	}	
//}


//��ʼ����ջ
Status_ InitStack(LinkStack& S) {
	//����һ����ջ��ջ��ָ���ÿ�
	S = NULL;
	return 0;
}

Status_ Push(LinkStack& S, SElemType e) {
	//��ջ������Ԫ��e
	LinkStack p = new StackNode;//�����½��
	p->data = e;//���½����������Ϊe
	p->next = S;//���½�����ջ��
	S = p;//�޸�ջ��ָ��Ϊp
	return OK;
}

void TraverseStack(LinkStack S) {
	LinkStack p = S;
	while (p) {
		cout << p->data;
		p = p->next;
	}
}

bool In(SElemType ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '#') {
		return true;
	}
	return false;
}

int Operate(ElemType a, ElemType b, SElemType ch) {
	switch (ch) {
	case'+':
		return a + b;
	case'-':
		return a - b;
	case'*':
		return a * b;
	case'/':
		return a / b;
	default:
		exit(ERROR);
	}
}
Status_ Pop(LinkStack& S, SElemType& e) {
	//ɾ��S��ջ��Ԫ�أ���e������ֵ
	if (S == NULL) return ERROR;//ջ��
	LinkStack p = S;
	//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	e = S->data;//��ջ��Ԫ�ظ���e
	S = S->next;//�޸�ջ��ָ��
	delete p;//�ͷ�ԭջ��Ԫ�صĿռ�
	return e;
}

SElemType GetTop(LinkStack& S) {
	//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S != NULL)
		return S->data;
}
//bool Gettop(LinkStack& S, SElemType& e) {
//	if (StackEmpty(S))return 0;
//	e = S->data; return 1;
//}

Status_ StackEmpty(LinkStack& S) {
	if (S == NULL)return true;
	return false;
}

Status_ ClearStack(LinkStack& S) {
	StackNode* p;
	p = S;
	while (S) {
		S = S->next;
		delete p;
		p = S;
	}
	return OK;
}

Status_ DestroyStack(LinkStack& S) {
	LinkStack p = S;
	while (S) {
		p = S;
		S = S->next;
		delete p;
	}
	return OK;
}

int opCH(char ch) {
	int i;
	switch (ch) {
	case'+':
		i = 0;
		break;
	case'-':
		i = 1;
		break;
	case'*':
		i = 2;
		break;
	case'/':
		i = 3;
		break;
	case'(':
		i = 4;
		break;
	case')':
		i = 5;
		break;
	case'#':
		i = 6;
		break;
	default:
		exit(ERROR);
	}
	return i;
}
//�Ƚ����ȼ�
Status_ Compare(SElemType op, SElemType ch) {
	char arr[7][7] = { '>','>','<','<','<','>','>',
					'>','>','<','<','<','>','>',
					'>','>','>','>','<','>','>',
					'>','>','>','>','<','>','>',
					'<','<','<','<','<','=','x',
					'>','>','>','>','x','>','>',
					'<','<','<','<','<','x','=' };
	int i, j;
	i = opCH(op);
	j = opCH(ch);
	return arr[i][j];
}

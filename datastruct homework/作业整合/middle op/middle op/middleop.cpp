#include"middleop.h"

//顺序栈的初始化
Status InitStack(SqStack& S)
{//构造一个空栈S
	//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	S.base = new ElemType[MAXSIZE];
	//存储分配失败
	if (!S.base)exit(OVERFLOW);
	//top初始为base，空栈
	S.top = S.base;
	//stacksize置为栈的最大容量MAXSIZE
	S.stacksize = MAXSIZE;
	return OK;
}
//顺序栈的入栈
Status Push(SqStack& S, ElemType e)
{//插入元素e为新的栈顶元素
	//栈满
	if (S.top - S.base == S.stacksize)return ERROR;
	//元素e压入栈顶，栈顶指针加1
	*S.top++ = e;
	return OK;
}
//遍历栈
void StackTraverse(SqStack& S) {
	ElemType* p = S.base;
	while (p < S.top) {
		cout << *p << " ";
		p++;
	}
}
//判断是否栈满
Status StackFull(SqStack S) {
	if (S.top - S.base == S.stacksize)
		return OK;
	else return ERROR;
}
//顺序栈的出栈
Status Pop(SqStack& S, ElemType& e)
{//删除S的栈顶元素，用e返回其值
	//栈空
	if (S.top == S.base) return ERROR;
	//栈顶指针减1，将栈顶元素赋给e
	e = *--S.top;
	return e;
}
Status GetTop(SqStack S)
{//返回S的栈顶元素，不修改栈顶指针
	//栈非空
	if (S.top != S.base)
		return *(S.top - 1);
}
Status ClearStack(SqStack& S) {
	if (S.base)S.base = S.top;
	return OK;
}
//判断栈是否为空
bool StackEmpty(SqStack S) {
	if (S.base == S.top)return true;
	else return false;
}
//销毁栈
Status DestroyStack(SqStack& S) {
	ElemType* p = S.base;
	S.base = S.top = NULL;
	delete[] p;
	S.stacksize = 0;
	return OK;
}
//实现数值转换
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


//初始化链栈
Status_ InitStack(LinkStack& S) {
	//构造一个空栈，栈顶指针置空
	S = NULL;
	return 0;
}

Status_ Push(LinkStack& S, SElemType e) {
	//在栈顶插入元素e
	LinkStack p = new StackNode;//生成新结点
	p->data = e;//将新结点数据域置为e
	p->next = S;//将新结点插入栈顶
	S = p;//修改栈顶指针为p
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
	//删除S的栈顶元素，用e返回其值
	if (S == NULL) return ERROR;//栈空
	LinkStack p = S;
	//用p临时保存栈顶元素空间，以备释放
	e = S->data;//将栈顶元素赋给e
	S = S->next;//修改栈顶指针
	delete p;//释放原栈顶元素的空间
	return e;
}

SElemType GetTop(LinkStack& S) {
	//返回S的栈顶元素，不修改栈顶指针
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
//比较优先级
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

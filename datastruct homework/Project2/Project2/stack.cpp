#include "stack.h"
//≥ı ºªØÀ≥–Ú’ª
void InitStack(SqStack& S) {
	//¥¥Ω®“ª∏ˆø’’ª
	S.base = new ElemType[MAXSIZE];
	if (S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	
}

//≈–∂œ’ªø’
bool StackEmpty(SqStack& S) {
	if (S.top == S.base)
		return OK;
}
//≈–∂œ’ª¬˙
bool StackFull(SqStack& S) {
	if (S.top - S.base == S.stacksize) 
		return ERROR;
}
//À≥–Ú’ª»Î’ª
void Push(SqStack& S, ElemType e) {
	
	*S.top = e;
	S.top++;
	
}
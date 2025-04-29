#include"middleop.h"
int main() {
	SqStack OPND;
	LinkStack OPTR;
	SElemType ch;
	SElemType theta;
	SElemType x;
	ElemType a;
	ElemType b;

	InitStack(OPND);
	InitStack(OPTR);
	Push(OPTR, '#');
	cin >> ch;
	while (ch != '#' || GetTop(OPTR) != '#') {
		if (!In(ch)) {
			Push(OPND, ch - 48);
			cin >> ch;
		}
		else {
			switch (Compare(GetTop(OPTR), ch)) {
			case'<':
				Push(OPTR, ch);
				cin >> ch;
				break;
			case'>':
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, b, theta));
				break;
			case'=':
				Pop(OPTR, x);
				cin >> ch;
				break;
			}
		}
	}

	cout << GetTop(OPND);


	return 0;
}
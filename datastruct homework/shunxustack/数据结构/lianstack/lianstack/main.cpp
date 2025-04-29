#include"lianstack.h"

int main() {
	LinkStack S;
	ElemType e = 0;
	//1）初始化一个栈，
	Init(S);
	//2）依次入栈1, 2, 3, 4, 5，6
	for (int i = 1; i <= 6; i++) {
		Push(S, i);
	}
	//3）查看栈顶元素并打印
	cout << "栈顶为" << GetTop(S, &e) << endl;
	//4）遍历
	Traverse(S);
	//5）出栈6次，并打印出栈的数据，如果不能出栈，屏幕输出：“栈空，不能出栈”
	for (int i = 1; i <= 6; i++) {
		Pop(S, e);
	}
	//6）依次入栈1, 2, 3, 4, 5, 6
	for (int i = 1; i <= 6; i++) {
		Push(S, i);
	}
	//7）清空栈
	Clear(S);
	//8）销毁栈
	Destory(S);
}
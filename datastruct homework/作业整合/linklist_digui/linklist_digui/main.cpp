#include"linklist.h"
int main() {
	LinkList L, r;
	cout << "请输入一系列整数,以-1结束" << endl;
	create(L);

	int a;
	cout << "正向打印无头结点单链表" << endl;
	print(L);
	cout << endl;
	cout << "逆向打印无头结点单链表" << endl;
	reverseprint(L);
	cout << endl;
	a = maxvalue(L);
	cout << "最大值是: " << a << endl;

	return 0;
}
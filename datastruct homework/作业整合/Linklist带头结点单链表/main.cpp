#include"Linklist.h"

int main() {
	LinkList L, La, Lb;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 5);
	ListTraverse(L);
	cout << " " << endl;

	ListInsert(L, 6, 6);
	ListTraverse(L);
	cout << " " << endl;

	int m = LocateElem(L, 5);
	cout << "请输入5的位置" << m << endl;
	int n = LocateElem(L, 6);
	cout << "请输入6的位置" << n << endl;
	int b = LocateElem(L, 2);
	cout << "请输入2的位置" << b << endl;


	ListInsert(L, 2, 7);
	ListInsert(L, 2, 8);
	ListInsert(L, 2, 9);
	ListInsert(L, 2, 10);
	ListInsert(L, 2, 11);
	ListTraverse(L);
	cout << " " << endl;

	int c;
	cout << ListDelete(L, 1, c) << endl;
	ListTraverse(L);
	cout << " " << endl;
	cout << ListDelete(L, 9, c) << endl;
	ListTraverse(L);
	cout << " " << endl;

	ClearList(L);
	cout << ListLength(L);
	cout << " " << endl;

	if (ListInsert(L, 2, 10) == 1) {
		cout << "成功插入" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}


	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 5);
	ListTraverse(L);
	DestroyList(L);
	cout << " " << endl;

	cout << "使用尾插法创建链表A：" << endl;
	CreateList_R(La, 4);
	cout << "链表元素为：" << endl;
	ListTraverse(La);
	cout << " " << endl;
	cout << "使用尾插法创建链表B：" << endl;
	CreateList_R(Lb, 3);
	cout << "链表元素为：" << endl;
	ListTraverse(Lb);
	cout << " " << endl;
	cout << "合并链表：" << endl;
	Lunion(La, Lb);
	ListTraverse(La);

	return 0;

}


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
	cout << "������5��λ��" << m << endl;
	int n = LocateElem(L, 6);
	cout << "������6��λ��" << n << endl;
	int b = LocateElem(L, 2);
	cout << "������2��λ��" << b << endl;


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
		cout << "�ɹ�����" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}


	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 5);
	ListTraverse(L);
	DestroyList(L);
	cout << " " << endl;

	cout << "ʹ��β�巨��������A��" << endl;
	CreateList_R(La, 4);
	cout << "����Ԫ��Ϊ��" << endl;
	ListTraverse(La);
	cout << " " << endl;
	cout << "ʹ��β�巨��������B��" << endl;
	CreateList_R(Lb, 3);
	cout << "����Ԫ��Ϊ��" << endl;
	ListTraverse(Lb);
	cout << " " << endl;
	cout << "�ϲ�����" << endl;
	Lunion(La, Lb);
	ListTraverse(La);

	return 0;

}


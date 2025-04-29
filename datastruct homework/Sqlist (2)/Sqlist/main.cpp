#include"sqlist.h"
int main() {
	Sqlist L;
	Sqlist La;
	Sqlist Lb;
	ElemType a[] = { 45,26,34,17,18 }, e = 16;
	ElemType b[] = { 12,26,43 };


	if (InitList(L)) {
		cout << "顺序表初始化完毕" << endl;
	}
	else {
		cout << "顺序表创建失败" << endl;
		exit(1);
	}


	cout << "利用ListInsert_Sq根据数组a[]创建线性表L：" << endl;
	for (int i = 1; i <= sizeof(a) / sizeof(ElemType); i++)
		ListInsert(L, i, a[i - 1]);
	ListTraverse(L);
	cout << endl;

	int pos = 4;
	cout << "在顺序表L的第" << pos << "个位置插入元素e,即" << endl;
	cout << '\'' << e << '\'' << ";" << endl;
	ListInsert(L, pos, e);
	ListTraverse(L);
	cout << endl;


	pos = 6;
	int delelem;
	cout << "删除顺序表L的第" << pos << "个元素的位置，并用变量delelem返回该元素：" << endl;
	ListDelete(L, pos, delelem);
	ListTraverse(L);
	cout << endl;

	pos = 3;
	int m;
	cout << "利用GetElem得到线性表L中第" << pos << "个元素的值，并用m返回该元素" << endl;
	GetElem(L, pos, m);
	cout << "m的值为：" << m << endl;
	ListTraverse(L);
	cout << endl;

	cout << "在顺序表L中查找第1个值与e,(即";
	cout << '\'' << e << '\'';
	cout << ")相同的元素，若找到，用i返回该位序，否则返回0：" << endl;
	pos = LocateElem(L, e);
	cout << '\'' << e << '\'';
	cout << "在顺序表L的第" << pos << "位" << endl;


	cout << "利用ClearList将线性表L置空：" << endl;
	ClearList(L);
	cout << "已置空" << endl;
	cout << endl;


	cout << "利用Destroy将线性表L销毁：" << endl;
	DestroyList(L);
	cout << "已销毁" << endl;
	cout << endl;


	if (InitList(La)) {
		cout << "顺序表初始化完毕" << endl;
	}
	else {
		cout << "顺序表创建失败" << endl;
		exit(1);
	}
	cout << "利用ListInsert_Sq根据数组a[]创建线性表La：" << endl;
	for (int i = 1; i <= sizeof(a) / sizeof(ElemType); i++)
		ListInsert(La, i, a[i-1]);
	ListTraverse(La);
	cout << endl;


	if (InitList(Lb)) {
		cout << "顺序表初始化完毕" << endl;
	}
	else {
		cout << "顺序表创建失败" << endl;
		exit(1);
	}
	cout << "利用ListInsert_Sq根据数组b[]创建线性表Lb：" << endl;
	for (int i = 1; i <= sizeof(b) / sizeof(ElemType); i++)
		ListInsert(Lb, i, b[i-1]);
	ListTraverse(Lb);
	cout << endl;

	cout << "输出合并后的线性表La:";
	Lunion(La, Lb);
	ListTraverse(La);


	return OK;

	
}
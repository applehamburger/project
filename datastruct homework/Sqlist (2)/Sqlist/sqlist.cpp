#include"sqlist.h"

Status InitList(Sqlist& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) exit(0);
	L.length = 0;
	return OK;
}
Status ListInsert(Sqlist& L, int i, ElemType e) {
	//i的合法性判断
	if ((i < 1) || (i > L.length + 1)) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
void ListTraverse(const Sqlist& L) {
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
}
int ListLength(const Sqlist& L) {
	for (int i = 1; i <= L.length; i++)
	{
		return i;
	}
}
bool ListEmpty(const Sqlist& L) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == 0)
			return true;
		else  return false;
	}
}
Status GetElem(Sqlist L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length)) return ERROR;
	e = L.elem[i - 1];
	return OK;
}
int LocateElem(Sqlist L, ElemType e) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;
		else return 0;
	}
}
Status ListDelete(Sqlist& L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length)) return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j < L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	L.length--;
	return OK;
}
Status ClearList(Sqlist& L) {
	L.length = 0;
	return OK;
}
Status DestroyList(Sqlist& L) {
	if (L.elem)
		delete[]L.elem;
	L.elem = NULL;
	L.length = 0;
	return OK;
}
void Lunion(Sqlist& La, Sqlist Lb) {
	int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
	for (int i = 1; i <= Lb_len; i++) {
		int m;
		GetElem(Lb, i, m);
		if (!LocateElem(La, m))
			ListInsert(La,++ La_len, m);
	}
}
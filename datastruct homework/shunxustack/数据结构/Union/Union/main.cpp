#include"Union.h"
int main() {
	int i;
	ElemType e;
	LinkList La;
	LinkList Lb;
	LinkList L;
	InitList(La);
	InitList(Lb);
	//CreateList_H(L);
	CreateList_R(La);
	CreateList_R(Lb);

	Union(La, Lb);
	//ListTraverse(La);
	return 0;
}
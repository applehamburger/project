#include"Union.h"
Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}
void CreateList_H(LinkList& L) {
	char e;
	while (true) {
		e = cin.get();
		if (e == '\n')break;
		LinkList s = new LNode;
		s->data = e;
		s->next = L->next;
		L->next = s;
	}
}
void CreateList_R(LinkList& L) {
	LinkList r = new LNode;
	r = L;
	char e;
	while (true) {
		LinkList p = new LNode;
		e = cin.get();
		if (e == '\n')break;
		p->data = e;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
void ListTraverse(const LinkList& L) {
	//����������L(��ӡ)
	LinkList p = L->next;
	while (p) {
		cout << p->data;
		p = p->next;
	}
}Status GetElem(LinkList L, int i) {
	//��e����L�е�i��Ԫ�ص�ֵ
	ElemType e;
	LinkList p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	//cout << e << endl;
	return e;
}
int LocateElem(LinkList L, ElemType e) {
	//�ڵ������в���ֵΪe��Ԫ�أ����������
	LinkList p = L->next;
	int i = 1;
	while (p && p->data != e) {
		p = p->next;
		i++;
	}
	if (!p)return ERROR;
	return OK;
}
Status ListInsert(LinkList& L, int i, ElemType e) {
	//�ڵ�����L�е�i��λ�ò����µ�Ԫ��e
	int j = 0;
	LinkList p = L;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)return ERROR;
	LinkList t = new LNode;
	t->data = e;
	t->next = p->next;
	p->next = t;
	return OK;
}
int ListLength(LinkList L) {
	//����L��Ԫ�ظ���
	int i = 0;
	LinkList p = L->next;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
void Union(LinkList& La, LinkList Lb) {
	LinkList pa = new LNode;
	LinkList pb = new LNode;
	LinkList qa = new LNode;
	ElemType e;

	for (pa = La; pa->next != NULL; pa = pa->next);
	for (pb = Lb; pb->next != NULL;) {
		e = pb->next->data;
		for (qa = La->next; qa != NULL && !LocateElem(La, e); qa = qa->next);
		if (qa == NULL) {
			pa->next = pb->next;
			pa = pa->next;
			pb->next = pb->next->next;
			pa->next = NULL;
		}
		else
			pb = pb->next;
	}
	ListTraverse(La);
}
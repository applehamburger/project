
#include"project4.h"

Status InitList(LinkList& L) {
	L = new LNode;//创建头结点
	L->next = NULL;
	return OK;
}
void CreateList_H(LinkList& L,int n) {
	L = new LNode;
	L->next = NULL;
	for(int i=0;i<n;i++){
		LinkList p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
void CreateList_R(LinkList& L,int n) {
	L = new LNode;
	L->next = NULL;
	LinkList r = L;
	for (int i = 0; i < n; i++) {
		LinkList p = new LNode;
		cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}
void ListTraverse(const LinkList& L) {
	LinkList p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}

int LocateElem(LinkList L, ElemType e) {
	int i = 1;
	LinkList p = L;
	while (p && p->data != e) {
		p = p->next;
		i++;
	}
	if (!p) return ERROR;
	else
		return i;
}
Status GetElem(LinkList L, int i, ElemType& e) {
	int j = 1;
	LinkList p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
 
Status ListInsert(LinkList& L, int i, ElemType e) {
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	LinkList s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList& L, int i, ElemType& e) {
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!p || !p->next || j > i - 1) return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}
bool ListEmpty(const LinkList& L) {
	if (!L->next)
		return true;
	return false;
}
int ListLength(const LinkList& L) {
	int count = 0;
	LinkList p = L->next;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}
Status DestroyList(LinkList& L) {
	while (L) {
		LinkList p = L->next;
		delete L;//从头节点开始依次删除
		L = p;
	}
	return OK;
}
void  ClearList(LinkList& L) {
	LinkList q = L->next;
	while (q) {
		LinkList p = q->next;
		delete q;
		q = p;
	}
	L->next= NULL;
}
//LinkList Find(LinkList L, ElemType x) {
//	LinkList p = L->next;
//	while (p != NULL && p->data != x)
//		p = p->next;
//	return p;
//}
//LinkList Locate(LinkList L, int i) {
//	if (i < 0) return NULL;
//	LinkList p = L;
//	int k = 0;
//	while (p != NULL && k < i) {
//		p = p->next;
//		k++;
//	}
//	return p;
//}
Status equal(int a, int b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
void Lunion(LinkList& La, LinkList &Lb) {
	LinkList pa, qa, pb;
	for (pa = La; pa->next != NULL; pa = pa->next);
	for (pb = Lb; pb->next != NULL;) {
		int e;
		e = pb->next->data;
		for (qa = La->next; qa != NULL && !equal(qa->data, e); qa = qa->next);
		if (qa == NULL) {
			pa->next = pb->next;
			pa = pa->next;
			pb->next = pb->next->next;
			pa->next = NULL;
		}
		else
			pb = pb->next;
	    
	}
}
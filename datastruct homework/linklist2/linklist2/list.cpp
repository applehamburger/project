#include<iostream>
#define NULL 0
#define OK 1
using namespace std;

typedef struct LNode {
	int data;
	LNode* next;
}LNode, * LinkList;


void create(LinkList& L) {
	int a;
	cout << "������һϵ������,��-1����" << endl;
	cin >> a;
	if (a == -1)
		L = NULL;
	else {
		L = new LNode;
		L->data = a;
		create(L->next);
	}
}

void print(LinkList L) {
	while (L) {
		cout << L->data << " ";
		L = L->next;
	}
}

void reverseprint(LinkList L) {
	if (L) {
		reverseprint(L->next);
		cout << L->data << " ";
	}
}

int maxvalue(LinkList L) {
	if (!L)
		return -1; // �������Ϊ�գ�����-1
	int max_val = L->data;
	while (L) {
		if (L->data > max_val) {
			max_val = L->data;
		}
		L = L->next;
	}
	return max_val;
}

int main() {
	LinkList L, r;
	create(L);

	int a;
	/*
	cout << "������һϵ������,��-1����" << endl;
	cin >> a;
	r = L;
	while (a != -1) {
		if (a < 0) {
			cin >> a;
			continue;
		}
		LinkList s = new LNode;
		s->data = a;
		s->next = NULL;
		r->next = s;
		r = s;
		cin >> a;
	}*/
	cout << "�����ӡ��ͷ��㵥����" << endl;
	print(L);
	cout << endl;
	cout << "�����ӡ��ͷ��㵥����" << endl;
	reverseprint(L);
	cout << endl;
	a = maxvalue(L);
	cout << "���ֵ��: " << a << endl;

	return 0;
}



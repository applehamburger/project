#include"linklist.h"



void create(LinkList& L) {
	int a;
	
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
		return -1; // 如果链表为空，返回-1
	int max_val = L->data;
	while (L) {
		if (L->data > max_val) {
			max_val = L->data;
		}
		L = L->next;
	}
	return max_val;
}

#include"linklist.h"
int main() {
	LinkList L, r;
	cout << "������һϵ������,��-1����" << endl;
	create(L);

	int a;
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
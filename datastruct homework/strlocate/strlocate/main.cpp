#include"strlocate.h"

int main() {
	HString S;
	HString T;
	char s[MAXSIZE];
	char t[MAXSIZE];
	cout << "����������S��" << endl;
	cin >> s;
	StrAssign(S, s);
	cout << "�������Ӵ�T��" << endl;
	cin >> t;
	StrAssign(T, t);

	cout << "����SΪ��" << endl;
	TraverseString(S);
	cout << "�Ӵ�TΪ��" << endl;
	TraverseString(T);

	int pos;
	cout << "�������S�ĵڼ�λ��ʼ����: ";
	cin >> pos;
	if (index(S, T, pos) == 0)
		cout << "δ�ҵ����Ӵ�" << endl;
	else cout << "��ʼλ�ã�" << index(S, T, pos)<< "  "<<"��ֹλ��"<< index(S, T, pos)+T.length<<endl;

	return 0;
}
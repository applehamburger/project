#include"sqlist.h"
int main() {
	Sqlist L;
	Sqlist La;
	Sqlist Lb;
	ElemType a[] = { 45,26,34,17,18 }, e = 16;
	ElemType b[] = { 12,26,43 };


	if (InitList(L)) {
		cout << "˳����ʼ�����" << endl;
	}
	else {
		cout << "˳�����ʧ��" << endl;
		exit(1);
	}


	cout << "����ListInsert_Sq��������a[]�������Ա�L��" << endl;
	for (int i = 1; i <= sizeof(a) / sizeof(ElemType); i++)
		ListInsert(L, i, a[i - 1]);
	ListTraverse(L);
	cout << endl;

	int pos = 4;
	cout << "��˳���L�ĵ�" << pos << "��λ�ò���Ԫ��e,��" << endl;
	cout << '\'' << e << '\'' << ";" << endl;
	ListInsert(L, pos, e);
	ListTraverse(L);
	cout << endl;


	pos = 6;
	int delelem;
	cout << "ɾ��˳���L�ĵ�" << pos << "��Ԫ�ص�λ�ã����ñ���delelem���ظ�Ԫ�أ�" << endl;
	ListDelete(L, pos, delelem);
	ListTraverse(L);
	cout << endl;

	pos = 3;
	int m;
	cout << "����GetElem�õ����Ա�L�е�" << pos << "��Ԫ�ص�ֵ������m���ظ�Ԫ��" << endl;
	GetElem(L, pos, m);
	cout << "m��ֵΪ��" << m << endl;
	ListTraverse(L);
	cout << endl;

	cout << "��˳���L�в��ҵ�1��ֵ��e,(��";
	cout << '\'' << e << '\'';
	cout << ")��ͬ��Ԫ�أ����ҵ�����i���ظ�λ�򣬷��򷵻�0��" << endl;
	pos = LocateElem(L, e);
	cout << '\'' << e << '\'';
	cout << "��˳���L�ĵ�" << pos << "λ" << endl;


	cout << "����ClearList�����Ա�L�ÿգ�" << endl;
	ClearList(L);
	cout << "���ÿ�" << endl;
	cout << endl;


	cout << "����Destroy�����Ա�L���٣�" << endl;
	DestroyList(L);
	cout << "������" << endl;
	cout << endl;


	if (InitList(La)) {
		cout << "˳����ʼ�����" << endl;
	}
	else {
		cout << "˳�����ʧ��" << endl;
		exit(1);
	}
	cout << "����ListInsert_Sq��������a[]�������Ա�La��" << endl;
	for (int i = 1; i <= sizeof(a) / sizeof(ElemType); i++)
		ListInsert(La, i, a[i-1]);
	ListTraverse(La);
	cout << endl;


	if (InitList(Lb)) {
		cout << "˳����ʼ�����" << endl;
	}
	else {
		cout << "˳�����ʧ��" << endl;
		exit(1);
	}
	cout << "����ListInsert_Sq��������b[]�������Ա�Lb��" << endl;
	for (int i = 1; i <= sizeof(b) / sizeof(ElemType); i++)
		ListInsert(Lb, i, b[i-1]);
	ListTraverse(Lb);
	cout << endl;

	cout << "����ϲ�������Ա�La:";
	Lunion(La, Lb);
	ListTraverse(La);


	return OK;

	
}
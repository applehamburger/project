#include"search.h"
int main() {
	SSTable ST;
	int key, loc, n;
	InitList(ST);
	cout << "������˳�����Ԫ�ظ�����" << endl;
	cin >> n;
	CreateST(ST, n);
	cout << "������Ҫ���ҵ�Ԫ�أ�" << endl;
	cin >> key;
	cout << "������Ҫ��ʼ���ҵ�λ�ã�" << endl;
	cin >> loc;
	cout << "˳����ң�" << endl;
	cout << Search_Seq(ST, key) << endl;
	cout << "˳����ҵĵݹ��㷨��" << endl;
	cout << SeqSearch(ST, key, loc) << endl;
	bubble_sort(ST, n);
	cout << "�����Ϊ��" << endl;
	Traverse(ST);
	cout << endl;
	cout << "�������۰���ҷǵݹ��㷨��" << endl;
	cout << Search_Bin(ST, 5) << endl;
	cout << "�������۰���ҵݹ��㷨��" << endl;
	cout << BinSearch(ST, 5, 0, ST.length) << endl;
	return 0;
}
#include"Search.h"
int main() {
	SSTable ST;
	int key, loc, n;
	InitSSTable(ST);
	cout << "������˳�����Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "������˳���" << endl;
	CreateSSTable(ST, n);
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
	//11 45 67 23 93 14 25 63 64 85 
	cout << endl;
	cout << "�������۰���ҷǵݹ��㷨��" << endl;
	cout << Search_Bin(ST, 63) << endl;
	cout << "�������۰���ҵݹ��㷨��" << endl;
	cout << BinSearch(ST, 63, 0, ST.length) << endl;
	return 0;
}
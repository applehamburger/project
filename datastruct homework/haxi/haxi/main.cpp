#include"haxi.h"
int main() {
	HashTable HT;
	int key;
	int n;
	int otherinfo;
	InitHashTable(HT);
	//���ϣ�����һЩ����
	cout << "���������ݣ�" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> key >> otherinfo;
		Insert(HT, key, otherinfo);
	}
	cout << "������Ҫ���ҵĹؼ��֣�" << endl;
	cin >> n;
	int index = Search(HT, n);
	if (index != -1)
		cout << "�ؼ���" << n << "��λ��Ϊ" << index << endl;
	else
		cout << "�ؼ���" << n << "�����ڣ�" << endl;
	return 0;
}
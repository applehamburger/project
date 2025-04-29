#include"haxi.h"
int main() {
	HashTable HT;
	int key;
	int n;
	int otherinfo;
	InitHashTable(HT);
	//向哈希表插入一些数据
	cout << "请输入数据：" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> key >> otherinfo;
		Insert(HT, key, otherinfo);
	}
	cout << "请输入要查找的关键字：" << endl;
	cin >> n;
	int index = Search(HT, n);
	if (index != -1)
		cout << "关键字" << n << "的位置为" << index << endl;
	else
		cout << "关键字" << n << "不存在！" << endl;
	return 0;
}
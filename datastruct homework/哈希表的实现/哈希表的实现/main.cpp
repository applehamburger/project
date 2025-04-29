#include"Hash.h"
int main() {
	HashTable HT;
	int key;
	int n;
	int otherinfo;
	InitHashTable(HT);
    //向哈希表插入一些数据
	cout << "请输入数据：" << endl;
	for (int i = 0; i < 10; i++) {
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
//11 100          
//45  200
//67 300
//23 400
//93 500
//14 600
//25 700
//63 800
//64 900
//85 906
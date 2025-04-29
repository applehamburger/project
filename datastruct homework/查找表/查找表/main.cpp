#include"Search.h"
int main() {
	SSTable ST;
	int key, loc, n;
	InitSSTable(ST);
	cout << "请输入顺序表中元素个数：" << endl;
	cin >> n;
	cout << "请输入顺序表：" << endl;
	CreateSSTable(ST, n);
	cout << "请输入要查找的元素：" << endl;
	cin >> key;
	cout << "请输入要开始查找的位置：" << endl;
	cin >> loc;
	cout << "顺序查找：" << endl;
	cout << Search_Seq(ST, key) << endl;
	cout << "顺序查找的递归算法：" << endl;
	cout << SeqSearch(ST, key, loc) << endl;
	bubble_sort(ST, n);
	cout << "排序后为：" << endl;
	Traverse(ST);
	//11 45 67 23 93 14 25 63 64 85 
	cout << endl;
	cout << "有序表的折半查找非递归算法：" << endl;
	cout << Search_Bin(ST, 63) << endl;
	cout << "有序表的折半查找递归算法：" << endl;
	cout << BinSearch(ST, 63, 0, ST.length) << endl;
	return 0;
}
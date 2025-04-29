#include"Search.h"
void InitSSTable(SSTable& ST) {
	ST.elem = new ElemType[MAXSIZE];
	if (!ST.elem)exit(OVERFLOW);
	ST.length = 0;
}
void CreateSSTable(SSTable& ST, int n) {
	for (int i = 0; i < n; i++) {
		cin >> ST.elem[i].key;
		ST.length++;
	}
}
int Search_Seq(SSTable ST, KeyType key) {
	//在顺序表ST中顺序查找其关键字等于key的数据元素
	//若找到则函数值为该元素在表中的位置，否则为0
	int i;
	ST.elem[ST.length].key = key;//哨兵  免去查找过程当中每一步都要检测整个表是否查找完毕           监视哨在高下标处
	//从后往前找
	for (i = 0; ST.elem[i].key != key; i++);
	return i;//找不到时i为0
}
int SeqSearch(SSTable ST, KeyType x, int loc) {
	//在数据表ST.elem[1]...ST.elem[n]中查找其关键字值
	//与给定值x匹配的元素，函数返回其在表中的位置
	//参数loc是在表中开始查找位置
	if (loc > ST.length)return 0;//查找失败
	else if (ST.elem[loc].key == x)return loc;//查找成功
	else return SeqSearch(ST, x, loc + 1);
}
void bubble_sort(SSTable &ST, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ST.elem[j + 1].key< ST.elem[j].key)
			{
				int temp = ST.elem[j].key;
				ST.elem[j].key = ST.elem[j + 1].key;
				ST.elem[j + 1].key = temp;
			}
		}
	}
}
void Traverse(SSTable ST) {
	for (int i = 0; i < ST.length; i++) {
		cout << ST.elem[i].key;
		cout << " ";
	}
}
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1, high = ST.length, mid;//置区间初值
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == ST.elem[mid].key)
			return mid;//找到待查元素
		else if (key < ST.elem[mid].key)
			high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
int BinSearch(SSTable ST, KeyType x, int low, int high) {
	int mid = 0;
	if (low <= high) {
		mid = (low + high) / 2;
		if (ST.elem[mid].key < x)
			mid = BinSearch(ST, x, mid + 1, high);
		else if (ST.elem[mid].key > x)
			mid = BinSearch(ST, x, low, mid - 1);
		else 
			return mid;
	}
}